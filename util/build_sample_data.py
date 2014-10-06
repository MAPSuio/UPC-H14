#! /usr/bin/env python

from sys import argv, stdout
from ConfigParser import RawConfigParser
from subprocess import call
import os

devnull = open(os.devnull, 'wb')

def cleanup():
    call(['rm -r tmp'], shell=True, stderr=devnull)

def build_problem_text(probdir, report_errors=False):
    print 'Building problem "%s"...' % probdir,
    stdout.flush()

    call(['mkdir tmp'], shell=True, stderr=devnull)
    call(['rm -r tmp/*'], shell=True, stderr=devnull)

    if call(['cp %s/domjudge-problem.ini tmp/' % probdir], shell=True, stderr=devnull):
        if report_errors:
            print ''
            print 'ERROR: "%s" must contain domjudge-problem.ini' % probdir
        else:
            print 'Failed'

        cleanup()
        return 1

    config = RawConfigParser()
    config.read('tmp/domjudge-problem.ini')
    probid = config.get('DOMJudge', 'probid')
    probname = config.get('DOMJudge', 'name')

    call(['mkdir tmp/%s' % probid], shell=True, stderr=devnull)

    if call(['cp %s/samples/* tmp/%s' % (probdir, probid)], shell=True, stderr=devnull):
        if report_errors:
            print ''
            print 'ERROR: "%s" must contain problem samples' % probdir
        else:
            print 'Failed'

        cleanup()
        return 1

    call(['mv tmp/%s samples/' % probid], shell=True, stdout=devnull)

    cleanup()

    print 'Done'

if len(argv) < 2:
    for directory in os.listdir('.'):
        if directory == 'template' or directory == 'util' \
            or directory == 'images' or directory == '.git' \
            or directory == 'problemset' or directory == 'build' \
            or directory == 'samples':
            continue

        if os.path.isdir(directory):
            build_problem_text(directory)
else:
    build_problem_text(argv[1], True)
