/*
** EPITECH PROJECT, 2025
** B-CCP-400-COT-4-1-panoramix-christiany.akotenou
** File description:
** main.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "panoramix.h"

int parse_positive_int(const char *arg)
{
    char *endptr = NULL;
    long val = strtol(arg, &endptr, 10);
    if (*endptr != '\0' || val <= 0 || val > INT_MAX)
        return -1;
    return (int)val;
}

int main(int argc, char **argv)
{
    shared_data_t shared;
    int nb_villagers;
    int nb_fights;

    if (init_shared_data(argc, argv, &shared) == 84)
        return 84;
    nb_villagers = parse_positive_int(argv[1]);
    nb_fights = parse_positive_int(argv[3]);
    pthread_t druid;
    pthread_t villagers[nb_villagers];
    villager_t data[nb_villagers];
    create_threads(&shared, nb_villagers, nb_fights, &druid, villagers, data);
    cleanup_threads(&shared, nb_villagers, &druid, villagers);
    return 0;
}
