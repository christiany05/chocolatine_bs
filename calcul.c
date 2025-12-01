/*
** EPITECH PROJECT, 2025
** chocolatine_bs
** File description:
** calcul.c
*/

#include <stdio.h>
#include <stdlib.h>
#include "calcule.h"

double string_to_double(const char *str)
{
    char *endptr;
    double val = strtod(str, &endptr);
    
    if (endptr == str || *endptr != '\0') {
        fprintf(stderr, "Erreur de conversion: '%s' n'est pas un nombre valide.\n", str);
        exit(EXIT_FAILURE);
    }
    return val;
}

double calculer(double a, double b, char operateur) {
    switch (operateur) {
        case '+':
            return a + b;
        case '-':
            return a - b;
        case '*':
            return a * b;
        case '/':
            if (b == 0.0) {
                fprintf(stderr, "Erreur: Division par zéro!\n");
                exit(EXIT_FAILURE);
            }
            return a / b;
        default:
            fprintf(stderr, "Erreur: Opérateur non reconnu.\n");
            exit(EXIT_FAILURE);
    }
}

int main(int argc, char *argv[])
{
    
    if (argc != 4) {
        fprintf(stderr, "Utilisation: %s <nombre1> <operateur> <nombre2>\n", argv[0]);
        fprintf(stderr, "Exemple: %s 10.5 + 4.2\n", argv[0]);
        return EXIT_FAILURE;
    }

    double nombre1 = string_to_double(argv[1]);
    char operateur = argv[2][0]; 
    double nombre2 = string_to_double(argv[3]);

    if (operateur != '+' && operateur != '-' && operateur != '*' && operateur != '/') {
        fprintf(stderr, "Erreur: Opérateur '%c' non valide. Utilisez +, -, * ou /.\n", operateur);
        return EXIT_FAILURE;
    }

    double resultat = calculer(nombre1, nombre2, operateur);

    printf("%.2lf %c %.2lf = %.2lf\n", nombre1, operateur, nombre2, resultat);

    return EXIT_SUCCESS;
}