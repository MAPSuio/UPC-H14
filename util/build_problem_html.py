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

    if call(['cp %s/problem.md tmp/' % probdir], shell=True, stderr=devnull):
        if report_errors:
            print ''
            print 'ERROR: "%s" must contain problem text' % probdir
        else:
            print 'Failed'

        cleanup()
        return 1

    call(['grip --gfm --export tmp/problem.md'], shell=True, stdout=devnull)
    call(['mv tmp/problem.html tmp/%s.html' % probid], shell=True)

    f = open('tmp/%s.html' % probid, 'r+')
    prob_text = f.read()
    f.seek(0)

    # center images
    img_head_needle = r' target="_blank"><img src="'
    img_head_replace = ' target="_blank"><center><img src="'
    img_tail_needle = r' style="max-width:100%;"></a>'
    img_tail_replace = ' style="max-width:100%;"></center></a>'

    prob_text = prob_text.replace(img_head_needle, img_head_replace)
    prob_text = prob_text.replace(img_tail_needle, img_tail_replace)

    # fix title
    title_needle = '<title>tmp/problem.md - Grip</title>'
    title_replace = '<title>%s</title>' % probname.replace('"', '')
    prob_text = prob_text.replace(title_needle, title_replace)

    f.write(prob_text)
    f.close()

    call(['mkdir -p problemset/html'], shell=True, stdout=devnull)
    call(['cp -r images problemset/images'], shell=True, stdout=devnull)
    call(['mv tmp/%s.html problemset/html/' % probid], shell=True, stdout=devnull)

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
