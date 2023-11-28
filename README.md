# Projet get_next_line

Bienvenue dans le projet get_next_line, un exercice de l'école 42 visant à implémenter une fonction permettant de lire ligne par ligne à partir d'un descripteur de fichier. La fonction `get_next_line` doit retourner une ligne à chaque appel, incluant le caractère de retour à la ligne, et passer à la ligne suivante lors des appels ultérieurs.

## Objectif

L'objectif principal de ce projet est de vous familiariser avec la gestion des descripteurs de fichiers, la lecture de fichiers, et la gestion dynamique de la mémoire en langage C.

## Utilisation

1. **Clonez le repository dans votre projet** :

   ```bash
   git clone https://github.com/thomaue/get_next_line.git

2. **Incluez le fichier d'en-tête get_next_line.h dans vos fichiers source** :
 
   ```bash
    #include "get_next_line.h"

3. **Appelez la fonction get_next_line pour lire une ligne à chaque appel.**

```c
int	main(void)
{
	int	fd;
	char *line;
	
	fd = open("file.txt", O_RDONLY);

	for(int i = 1; i <= 20; i++)
	{
		line = get_next_line(fd);
		printf("%d - %s",i, line);
		free(line);
	}
	close(fd);
	return (0);
}
```
4. **Compilez votre programme avec la fonction get_next_line** :

   ```bash
   gcc -o mon_programme mes_sources.c get_next_line/*.c -D BUFFER_SIZE=32


