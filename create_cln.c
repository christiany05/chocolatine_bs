/*
** EPITECH PROJECT, 2024
** B-CCP-400-COT-4-1-panoramix-christiany.akotenou
** File description:
** create_cln.c
*/

#include "panoramix.h"

void create_threads(shared_data_t *shared, int nb_villagers,
                    int nb_fights, pthread_t *druid,
                    pthread_t *villagers, villager_t *data)
{
    pthread_create(druid, NULL, druid_thread, shared);
    for (int i = 0; i < nb_villagers; ++i) {
        data[i].id = i;
        data[i].nb_fights = nb_fights;
        data[i].shared = shared;
        pthread_create(&villagers[i], NULL, villager_thread, &data[i]);
    }
}

void cleanup_threads(shared_data_t *shared, int nb_villagers,
                    pthread_t *druid, pthread_t *villagers)
{
    for (int i = 0; i < nb_villagers; ++i)
        pthread_join(villagers[i], NULL);
    pthread_join(*druid, NULL);
    pthread_mutex_destroy(&shared->mutex);
    sem_destroy(&shared->sem_pot_empty);
    sem_destroy(&shared->sem_pot_full);
}