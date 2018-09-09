# Rush_42_Hotrace
Hotrace is a command line program, made in a maximum of 48 hours.
The aim of this project is to make a tiny search engine, that takes a file as input and displays results directly onto standard output. The execution speed was mesured by an external tool and all results were compared with result of others students.

## Usage:

In a terminal, with executable and target file in current folder:
```
./hotrace < filename
```

##### File:

A file is divided in two parts, separated by an empty line:
1. some data with the format :
```
key
value
key
value
etc.
```

2. A list of keys


##### Example of file:

```
un
1
deux
2
trois
3
quatre
4
cinq
5

un
deux
cinq
sept
neuf
```

##### The program must first:
- memorize each key/value provided in the first part of the file.

##### Then, for each key in the list (second part of the file):
- should display either the matching value, or display an error ( "not found" )

##### Exemple of output:
```
un: 1
deux: 2
cinq: 5
sept: Not found
neuf: Not found
```
