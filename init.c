/*
** EPITECH PROJECT, 2024
** B-CCP-400-COT-4-1-panoramix-christiany.akotenou
** File description:
** init.c
*/

#include "panoramix.h"

int init_shared_data(int argc, char **argv, shared_data_t *shared)
{
    if (argc != 5) {
        printf("USAGE: ./panoramix <nb_villagers> ");
        printf("<pot_size> <nb_fights> <nb_refills>\n");
        return 84;
    }
    int nb_villagers = parse_positive_int(argv[1]);
    int pot_size = parse_positive_int(argv[2]);
    int nb_fights = parse_positive_int(argv[3]);
    int nb_refills = parse_positive_int(argv[4]);
    if (nb_villagers <= 0 || pot_size <= 0 || nb_fights <= 0 || nb_refills <= 0) {
        fprintf(stderr, "Values must be > 0.\n");
        return 84;
    }
    *shared = (shared_data_t) {
        .pot_servings = pot_size,
        .pot_size = pot_size,
        .nb_refills_left = nb_refills,
        .stop = false,
    };
    pthread_mutex_init(&shared->mutex, NULL);
    sem_init(&shared->sem_pot_empty, 0, 0);
    sem_init(&shared->sem_pot_full, 0, 0);
    return 0;
}
