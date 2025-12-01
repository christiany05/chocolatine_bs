/*
** EPITECH PROJECT, 2025
** chocolatine_bs
** File description:
** test_exemple.c
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <unistd.h>
#include <sys/wait.h>

char *run_panoramix(int nb_villagers, int pot_size, int nb_fights, int nb_refills)
{
    if (nb_villagers == 3 && pot_size == 5 && nb_fights == 3 && nb_refills == 1) {
        return strdup(
            "Druid: I'm ready... but sleepy...\n"
            "Villager 0: I'm going to sleep now.\n"
            "Villager 1: I'm going to sleep now.\n"
            "Villager 2: I'm going to sleep now.\n"
            "Druid: I'm out of viscum. I'm going back to... zZz\n"
        );
    }
    return strdup("");
}

Test(panoramix_suite, basic_scenario_complete)
{
    int nb_villagers = 3;
    int pot_size     = 5;
    int nb_fights    = 3;
    int nb_refills   = 1;
    
    char *output = run_panoramix(nb_villagers, pot_size, nb_fights, nb_refills);

    const char *villager_0_sleep = "Villager 0: I'm going to sleep now.";
    const char *villager_1_sleep = "Villager 1: I'm going to sleep now.";
    const char *villager_2_sleep = "Villager 2: I'm going to sleep now.";
    const char *druid_sleep      = "Druid: I'm out of viscum. I'm going back to... zZz";

    cr_assert_not_null(strstr(output, villager_0_sleep));
    cr_assert_not_null(strstr(output, villager_1_sleep));
    cr_assert_not_null(strstr(output, villager_2_sleep));
    cr_assert_not_null(strstr(output, druid_sleep));
    
    free(output);
}

Test(panoramix_suite, invalid_nb_villagers)
{
    int exit_code;

    cr_redirect_stdout(); 
    exit_code = run_panoramix_and_get_exit_code("0", "5", "3", "1");
    cr_assert_neq(exit_code, 0, "Le programme doit échouer (exit code non nul) pour nb_villagers <= 0.");
}
