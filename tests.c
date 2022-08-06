#include <check.h>

#include "headers/parse.h"
#include "headers/polish_notation.h"
#include "headers/stack.h"

START_TEST(Test1) {
    ck_assert_int_eq(calc("1 1 +", 0), 2);
}
END_TEST

START_TEST(Test2) {
    ck_assert_int_eq(calc("3 2 -", 0), 1);
}
END_TEST

START_TEST(Test3) {
    ck_assert_int_eq(calc("3 x *", 4), 12);
}
END_TEST

START_TEST(Test4) {
    ck_assert_int_eq(calc("3 3 ~ +", 0), 0);
}
END_TEST

START_TEST(Test5) {
    ck_assert_int_eq(calc("0 A", 0), 0);
}
END_TEST

START_TEST(Test6) {
    ck_assert_int_eq(calc("3 3 /", 0), 1);
}
END_TEST

START_TEST(Test7) {
    ck_assert_int_eq(calc("3 2 %", 0), 1);
}
END_TEST

START_TEST(Test8) {
    ck_assert_int_eq(calc("0 B", 0), 0);
}
END_TEST

START_TEST(Test9) {
    ck_assert_int_eq(calc("4 2 ^", 0), 16);
}
END_TEST

START_TEST(Test10) {
    ck_assert_int_eq(calc("1 C", 0), 0);
}
END_TEST

START_TEST(Test11) {
    ck_assert_int_eq(calc("0 D", 0), 1);
}
END_TEST

START_TEST(Test12) {
    ck_assert_int_eq(calc("0 E", 0), 0);
}
END_TEST

START_TEST(Test13) {
    ck_assert_int_eq(calc("0 F", 0), 0);
}
END_TEST

START_TEST(Test14) {
    ck_assert_int_eq(calc("36 G", 0), 6);
}
END_TEST

START_TEST(Test15) {
    ck_assert_int_eq(calc("1 H", 0), 0);
}
END_TEST

START_TEST(Test16) {
    ck_assert_int_eq(calc("10 I", 0), 1);
}
END_TEST

START_TEST(Test17) {
    char str[256] = "1+1";
    to_postfix(str);
    ck_assert(strcmp(str, "1 1 + "));
}
END_TEST

START_TEST(Test18) {
    char str[256] = "(1+x)*2";
    to_postfix(str);
    ck_assert(strcmp(str, "1 x + 2 * "));
}
END_TEST

START_TEST(Test19) {
    char str[256] = "asinsinacoscosatantansqrtlnlog";
    replace_all(str);
    ck_assert_str_eq(str, "ABCDEFGHI");
}
END_TEST

int main(void) {
    Suite *s1 = suite_create("Core");
    TCase *tc1_1 = tcase_create("Core");
    SRunner *sr = srunner_create(s1);
    int nf;

    suite_add_tcase(s1, tc1_1);
    tcase_add_test(tc1_1, Test1);
    tcase_add_test(tc1_1, Test2);
    tcase_add_test(tc1_1, Test3);
    tcase_add_test(tc1_1, Test4);
    tcase_add_test(tc1_1, Test5);
    tcase_add_test(tc1_1, Test6);
    tcase_add_test(tc1_1, Test7);
    tcase_add_test(tc1_1, Test8);
    tcase_add_test(tc1_1, Test9);
    tcase_add_test(tc1_1, Test10);
    tcase_add_test(tc1_1, Test11);
    tcase_add_test(tc1_1, Test12);
    tcase_add_test(tc1_1, Test13);
    tcase_add_test(tc1_1, Test14);
    tcase_add_test(tc1_1, Test15);
    tcase_add_test(tc1_1, Test16);
    tcase_add_test(tc1_1, Test17);
    tcase_add_test(tc1_1, Test18);
    tcase_add_test(tc1_1, Test19);

    srunner_run_all(sr, CK_ENV);
    nf = srunner_ntests_failed(sr);
    srunner_free(sr);

    return nf == 0 ? 0 : 1;
}
