# UiO Programming Challenge H14
Dette er oppgaverepoet for UPC høsten 2014. Informasjon herfra må ikke deles med personer utenfor oppgavegruppa før etter konkurransen.

For de som er med i oppgavegruppa er det to arbeidsoppgaver her inne:

- Lage oppgaver
- Lese/verifisere/lage løsninger oppgaver

## Inspirasjon
Oppgavene til UPC skal være enklere enn til NCPC. Målgruppen er primært studenter som nå går tredjesemester, og de mest interesserte av førsteårsstudentene.

Av 12 oppgaver ønsker vi at en gjennomsnittlig tredjesemester-/flink førstesemesterstudent skal klare rundt seks oppgaver. De neste seks oppgavene kan være vanskeligere, og det meningen at ingen skal klare/rekke å gjøre alle oppgavene.

Se [fjorårets oppgaver](https://github.com/MAPSuio/python-challenge-2014/blob/master/README.md) fra MAPS Python Challenge, eller tidligere [NCPC-oppgaver](https://ncpc.idi.ntnu.no) for inspirasjon.

Noen idéer til oppgaver:

- En veldig enkel oppgave (a la QueroPark)
- Topologisk sortering, fotballkamper (Joakim)
- Korteste vei something (Ola)
- Leftist/fibonacci heap, sykehuskø + sammenslåing
- Bredde-først, stengte gater i Kristiansand
- Noe numerisk, integrasjon, derivasjon etv.
- Grid, maks antall steg, vanskelig
- Krig (kortspill)
- Matching
- Packing
- Myntspill (Ola)
- Noe med parsing av ASCII-art

## Judgeserver
Til gjennomføringen av konkurransen kommer vi til å bruke [DOMJudge](https://domjudge.org). DOMJudge lar deg laste opp kildekoden til en løsning, som kompileres og kjøres mot testcasene.

Vi har en server kjørende med oppgavene fra MAPS Python Challenge fra i fjor pluss noen nye oppgaver. På denne serveren kan dere se hvordan det fungerer for deltakerne, og laste opp nye oppgaver for å teste.

Serveradresse: [https://178.62.242.80](https://178.62.242.80) (sertifikatet er selvsignert)

Admin-bruker; `admin`, passord: `ech748`  
Deltaker-bruker: `foo`, passord: `foo`

## Hvordan lage en oppgave
En oppgave består i hovedsak av en oppgavetekst som bl.a. definerer et input- og outputformat, og et sett med testcaser som besvarelser skal valideres mot.

I tillegg må det lages fasit/løsningsforslag til oppgaven. Disse brukes til automatisk verifisering av alle testcasene.

Alle oppgaver må løses og godkjennes av minst én annen person enn oppgaveforfatter.

Her er en trinn-for-trinn beskrivelse av alt man må gjøre for å lage en oppgave som er klar til å lastes opp til testserveren.

1. Finn på problemtittel, og gi oppgaven en meningsgivende ID. IDen må være alfanumerisk og maksimalt 8 tegn lang.
2. Kopier mappen `template`, og gi kopien IDen du kom opp med som navn
3. Fyll ut problemtittel og -forfatter i `README.md`
4. Fyll ut problem-ID og -tittel i `domjudge-problem.ini`
5. Fyll ut `problem.md`
6. Legg ev. bilder i `images`
7. Lag ett eller flere eksempeltestcaser. Gi testcasene filnavn på formen `X.sample.in` og `X.sample.out` og legg dem i mappen `samples`.
8. Lag testcaser. Gi testcasene filnavn på formen `X.in` og `X.out` og legg dem i mappen `testdata`
9. Lag én eller flere løsningsforslag. Det kan være en god idé å lage løsninger som er for trege eller feil. Skriv `@EXPECTED_RESULTS@: CORRECT` som en kommentar øverst i løsningskoden. Bytt  `CORRECT` med `TIMEOUT` eller `WRONG-ANSWER` etter hva som passer. Dette brukes til automatisk testing.
10. Fyll ut `solution.md`

Legg oppgaven inn i listen under når du er ferdig med punktene over!

### Hvordan laste opp en oppgave
Når alle punktene over er på plass, kan oppgaven pakkes og klargjøres for DOMJudge ved hjelp av `util/build_problem.py`. Stå i roten av repoet og kjør f.eks. `python util/build_problem.py bitmean` for å bygge problemet `bitmean`. Resultatet er en zip-fil med samme navn som problemet, som legges i mappen `build`.

Deretter:

1. Logg inn på DOMJudge-serveren med infoen som står over 
2. Gå til `Problems`
3. Velg zip-filen med file-pickeren helt nederst på siden og trykk upload

For å laste opp ny versjon av et problem må den gamle slettes først.

## Hvordan lage testcaser
Testcasene skal (ideelt) faile alle løsninger som ikke oppfyller alle kravene i oppgaveteksten. Dette betyr at alle edgecaser bør sjekkes av testcasene.

Hvis oppgaven er ment å skulle løses med en bestemt algoritme (med en gitt kompleksitet) bør du lage testcaser som sørger for at andre løsninger (f.eks. brute force) bruker for lang tid. I utgangspunktet bør riktig løsninger finne svaret på mindre enn ett sekund. Dette kan endres i `domjudge-problem.ini`.

## Oppgaver

### [A bit mean](bitmean)
__Algoritme/problemsjanger__: Triksing med binære tall  
__Forfatter__: martinvl  
__Løst av__: martinvl  
__Status__: Ferdig, og godkjent

### [Artificial three-year-old](artifi)
__Algoritme/problemsjanger__: Sjekke om en streng er `yes`  
__Forfatter__: martinvl  
__Løst av__: martinvl  
__Status__: Ferdig, men ikke godkjent

### [Festival area](festival)
__Algoritme/problemsjanger__: Areal av polygon  
__Forfatter__: martinvl  
__Løst av__: martinvl

### [Happy birthday to you](birthday)
__Algoritme/problemsjanger__: Skuddår og dato-iterering  
__Forfatter__: joakimjl  
__Løst av__: joakimjl

### [A healthy supply of ministers](healthy)
__Algoritme/problemsjanger__: Heap  
__Forfatter__: martinvl  
__Løst av__: martinvl  
__Status__: Ferdig, men ikke godkjent

### [I'd rather walk alone](football)
__Algoritme/problemsjanger__: Topografisk sortering  
__Forfatter__: joakimjl  
__Løst av__: joakimjl

### [The Fibonacci Rabbits](fibez)
__Algoritme/problemsjanger__: Fibonacci  
__Forfatter__: hennilu  
__Løst av__: hennilu

### [Kristiansand road work](kristian)
__Algoritme/problemsjanger__: BFS korteste vei  
__Forfatter__: martinvl  
__Løst av__: martinvl  
__Status__: Ferdig, og godkjent av Håkon

### [The pinmaker](pinmaker)
__Algoritme/problemsjanger__: Evaluering av differenslikning  
__Forfatter__: martinvl  
__Løst av__: martinvl  
__Status__: Ferdig, men ikke godkjent

### [The pinmaker 2](pinmaker2)
__Algoritme/problemsjanger__: Evaluering av differenslikning (i O(log n)))  
__Forfatter__: martinvl  
__Løst av__: martinvl  
__Status__: Ferdig, men ikke godkjent

### [The prize commitee](prize)
__Algoritme/problemsjanger__: Sortering, finne element  
__Forfatter__: martinvl  
__Løst av__: martinvl  
__Status__: Ferdig, godkjent av Håkon

### [Quidditch breakup](quid)
__Algoritme/problemsjanger__: Min cut  
__Forfatter__: martinvl  
__Løst av__: martinvl

### [Roundabout madness](rabout)
__Algoritme/problemsjanger__: Problemløsning  
__Forfatter__: olalia  
__Løst av__: olalia  
__Status__: Ferdig, men ikke godkjent

### [Walking the dog](walk)
__Algoritme/problemsjanger__: Problemløsning/analyse  
__Forfatter__: olalia  
__Løst av__:

### [Something, something network](ssnw)
__Algoritme/problemsjanger__: Datakommunikasjon  
__Forfatter__: sjurtf/hennilu  
__Løst av__: sjurtf/hennilu  
__Status__: Ferdig, men ikke godkjent 

### [War](war)
__Algoritme/problemsjanger__: Simulere kortspillet krig  
__Forfatter__: hawken  
__Løst av__: hawken  
__Status__: Ferdig, men ikke godkjent
