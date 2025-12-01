/*
** EPITECH PROJECT, 2025
** chocolatine_bs
** File description:
** test_exemple.c
*/
#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../calcule.h"
#include <math.h>
#define EPSILON 0.00001


Test(Calculer, addition_positive)
{
    cr_assert_float_eq(calculer(5.0, 3.0, '+'), 8.0, EPSILON, "5.0 + 3.0 devrait être 8.0");
}

Test(Calculer, soustraction_negative)
{
    cr_assert_float_eq(calculer(5.0, 10.0, '-'), -5.0, EPSILON, "5.0 - 10.0 devrait être -5.0");
}

Test(Calculer, multiplication_flottante)
{
    cr_assert_float_eq(calculer(2.5, 2.0, '*'), 5.0, EPSILON, "2.5 * 2.0 devrait être 5.0");
}

Test(Calculer, division_standard)
{
    cr_assert_float_eq(calculer(10.0, 4.0, '/'), 2.5, EPSILON, "10.0 / 4.0 devrait être 2.5");
}

Test(Calculer, division_par_zero, .exit_code = 1, .init = cr_redirect_stderr)
{
    calculer(5.0, 0.0, '/'); 
}

Test(StringToDouble, conversion_valide)
{
    cr_assert_float_eq(string_to_double("123.45"), 123.45, EPSILON, "La conversion de '123.45' a échoué.");
}

Test(StringToDouble, conversion_negative)
{
    cr_assert_float_eq(string_to_double("-50.0"), -50.0, EPSILON, "La conversion de '-50.0' a échoué.");
}

Test(StringToDouble, conversion_invalide, .exit_code = 1, .init = cr_redirect_stderr)
{
    string_to_double("abc"); 
}

Test(StringToDouble, conversion_partielle, .exit_code = 1, .init = cr_redirect_stderr)
{
    string_to_double("10.0a"); 
}