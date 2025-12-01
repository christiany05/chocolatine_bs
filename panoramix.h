/*
** EPITECH PROJECT, 2025
** B-CCP-400-COT-4-1-panoramix-christiany.akotenou
** File description:
** panoramix.h
*/

#ifndef PANORAMIX_H
#define PANORAMIX_H

#include <pthread.h>
#include <semaphore.h>
#include <stdbool.h>
#include <stdio.h>

typedef struct s_shared_data {
    int pot_servings;
    int pot_size;
    int nb_refills_left;
    int nb_villagers;
    bool stop;

    int villagers_finished;

    pthread_mutex_t mutex;
    sem_t sem_pot_empty;
    sem_t sem_pot_full;
} shared_data_t;

typedef struct s_villager {
    int id;
    int nb_fights;
    shared_data_t *shared;
} villager_t;

void *villager_thread(void *arg);
void *druid_thread(void *arg);
int init_shared_data(int argc, char **argv, shared_data_t *shared);
void create_threads(shared_data_t *shared, int nb_villagers,
                    int nb_fights, pthread_t *druid,
                    pthread_t *villagers, villager_t *data);
void cleanup_threads(shared_data_t *shared, int nb_villagers,
                    pthread_t *druid, pthread_t *villagers);
int parse_positive_int(const char *arg);

#endif // PANORAMIX_H
