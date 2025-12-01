/*
** EPITECH PROJECT, 2025
** chocolatine_bs
** File description:
** test_exemple.c
*/

#include <criterion/criterion.h>
#include <criterion/logging.h>

Test(example, basic_test)
{
    cr_assert_eq(1 + 1, 2, "1 + 1 devrait être égal à 2");
}

