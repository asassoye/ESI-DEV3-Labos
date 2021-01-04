# [DEV3] Laboratoires

Mes solutions des TD's de l'UE DEV3 à l'École Supérieur d'Informatique de Bruxelles

![GitHub top language](https://img.shields.io/github/languages/top/asassoye/ESI-DEV3-Labos?style=for-the-badge)
![GitHub](https://img.shields.io/github/license/asassoye/ESI-DEV3-Labos?style=for-the-badge)
![GitHub last commit](https://img.shields.io/github/last-commit/asassoye/ESI-DEV3-Labos?style=for-the-badge)
![GitHub Workflow Status](https://img.shields.io/github/workflow/status/asassoye/ESI-DEV3-Labos/Build/master?style=for-the-badge)

## Structure des fichiers

```
.
├── common
│   ├── src
│   │   ├── mathesi.c
│   │   ├── mathesi.cpp
│   │   ├── mathesi.h
│   │   ├── mathesi.hpp
│   │   ├── utilscpp.cpp
│   │   └── utilscpp.hpp
│   ├── test
│   │   ├── mathesicpptest.cpp
│   │   └── tests-main.cpp
│   └── CMakeLists.txt
├── i1
│   ├── src
│   │   ├── main.c
│   │   ├── primestat.c
│   │   ├── primestat.h
│   │   ├── statsample.c
│   │   └── statsample.h
│   ├── CMakeLists.txt
│   └── interro.pdf
├── i2
│   ├── src
│   │   └── main.cpp
│   └── CMakeLists.txt
├── td01
│   ├── src
│   │   └── main.c
│   ├── CMakeLists.txt
│   └── td01_c.pdf
├── td02
│   ├── src
│   │   ├── main.c
│   │   ├── tableaux.c
│   │   └── tableaux.h
│   ├── CMakeLists.txt
│   └── td02_c.pdf
├── td03
│   ├── src
│   │   ├── main.c
│   │   ├── str.c
│   │   └── str.h
│   ├── CMakeLists.txt
│   └── td03_c.pdf
├── td04
│   ├── src
│   │   ├── main.c
│   │   ├── PrimeFactor.c
│   │   ├── PrimeFactor.h
│   │   ├── PrimeFactorization.c
│   │   ├── PrimeFactorization.h
│   │   ├── td04.c
│   │   └── td04.h
│   ├── CMakeLists.txt
│   └── td04_c.pdf
├── td05
│   ├── src
│   │   ├── main.c
│   │   ├── slcircularlist.c
│   │   ├── slcircularlist.h
│   │   ├── slcircularlist_utility.c
│   │   ├── slcircularlist_utility.h
│   │   ├── slnode.c
│   │   ├── slnode.h
│   │   ├── slnode_utility.c
│   │   ├── slnode_utility.h
│   │   └── value_t.h
│   ├── CMakeLists.txt
│   ├── td05_c.pdf
│   └── td05_c_withAppendix.pdf
├── td06
│   ├── src
│   │   └── main.cpp
│   ├── CMakeLists.txt
│   └── td06_cpp.pdf
├── td07
│   ├── src
│   │   ├── main.cpp
│   │   ├── td07.cpp
│   │   └── td07.hpp
│   ├── CMakeLists.txt
│   └── td07_cpp.pdf
├── td08
│   ├── src
│   │   ├── fraction_constexpr.hpp
│   │   ├── fraction.cpp
│   │   ├── fraction.hpp
│   │   ├── main.cpp
│   │   ├── sign.cpp
│   │   └── sign.hpp
│   ├── test
│   │   ├── fraction_all.cpp
│   │   ├── fraction_constexprTest.cpp
│   │   ├── fractiontest.cpp
│   │   └── signtest.cpp
│   ├── CMakeLists.txt
│   ├── td08_cpp.pdf
│   └── td08_cpp_withAppendix.pdf
├── td09
│   ├── src
│   │   ├── draw.hpp
│   │   ├── item.hpp
│   │   ├── lotto.hpp
│   │   ├── main.cpp
│   │   ├── parameter.hpp
│   │   └── pronostic.hpp
│   ├── test
│   ├── CMakeLists.txt
│   ├── td09_cpp.pdf
│   └── td09_cpp_withAppendix.pdf
├── CMakeLists.txt
├── doxygen
├── LICENSE
├── Makefile
└── README.md
```

## Build

Pour compiler executez la commande suivante

```bash
$ make
```

Pour compiler en debug:

```bash
$ make debug
```

Pour compiler les docs:

```bash
$ make docs
```

Pour executer les tests:

```bash
$ make test
```

### Executer un TD

Après avoir compilé:

```bash
$ ./{td}/build/{env}/{td}
```

avec:

- env ∈ {`Release`,`Debug`}:
- td ∈ {`td01`, `td02`,`td03`,`td04`,`td01`,`td05`,`td06`,`td07`, `td08`, `td09`}

### Executer une interrogation

Après avoir compilé:

```bash
$ ./i1/build/{env}/interro1
```

avec `env` ∈ {`Release`,`Debug`}:

*Si vous n'arrivez pas a compiler l'interrogation avec la commande `make` voici une alternative*

```bash
$ make interro1
```

### Executer l'examen de janvier

Après avoir compilé:

```bash
$ ./i2/build/{env}/examen
```

avec `env` ∈ {`Release`,`Debug`}:

*Si vous n'arrivez pas a compiler l'interrogation avec la commande `make` voici une alternative*

```bash
$ make examen
```

### Clean les builds

```bash
$ make clean
```
