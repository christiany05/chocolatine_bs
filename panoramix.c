/*
** EPITECH PROJECT, 2025
** B-CCP-400-COT-4-1-panoramix-christiany.akotenou
** File description:
** panoramix.c
*/

#include "panoramix.h"
#include <stdio.h>
#include <unistd.h>

void handle_druid_wakeup(shared_data_t *shared)
{
    printf("Druid: Ah! Yes, yes, I'm awake! Working on it! ");
    printf("Beware I can only make %d more refills after this one.\n",
           shared->nb_refills_left - 1);
    shared->pot_servings = shared->pot_size;
    shared->nb_refills_left--;
}

void *druid_thread(void *\
arg)
{
    shared_data_t *shared = (shared_data_t *)arg;

    printf("Druid: I'm ready... but sleepy...\n");
    while (1) {
        sem_wait(&shared->sem_pot_empty);
        pthread_mutex_lock(&shared->mutex);
        if (shared->nb_refills_left <= 0) {
            shared->stop = true;
            pthread_mutex_unlock(&shared->mutex);
            sem_post(&shared->sem_pot_full);
            break;
        }
        handle_druid_wakeup(shared);
        pthread_mutex_unlock(&shared->mutex);
        sem_post(&shared->sem_pot_full);
    }
    printf("Druid: I'm out of viscum. I'm going back to... zZz\n");
    return NULL;
}

void handle_villager_action(villager_t *v)
{
    if (v->shared->pot_servings == 0) {
        printf("Villager %d: Hey Pano wake up! We need more potion.\n", v->id);
        sem_post(&v->shared->sem_pot_empty);
        pthread_mutex_unlock(&v->shared->mutex);
        sem_wait(&v->shared->sem_pot_full);
        pthread_mutex_lock(&v->shared->mutex);
    }
    if (v->shared->stop && v->shared->pot_servings == 0) {
        pthread_mutex_unlock(&v->shared->mutex);
        printf("Villager %d: No more potion. I'm going back to the village.\n", v->id);
        return;
    }
    v->shared->pot_servings--;
    printf("Villager %d: I need a drink... I see %d servings left.\n",
    v->id, v->shared->pot_servings);
    pthread_mutex_unlock(&v->shared->mutex);
    printf("Villager %d: Take that roman scum! Only %d left.\n",
    v->id, v->nb_fights - 1);
}

void *villager_thread(void *arg)
{
    villager_t *v = (villager_t *)arg;

    printf("Villager %d: Going into battle!\n", v->id);
    for (int i = 0; i < v->nb_fights; ++i) {
        pthread_mutex_lock(&v->shared->mutex);
        handle_villager_action(v);
    }
    printf("Villager %d: I'm going to sleep now.\n", v->id);
    return NULL;
}
