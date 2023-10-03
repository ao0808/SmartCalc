#ifndef SRC_S21_CALK_H_
#define SRC_S21_CALK_H_

#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct pars_format {
  int count;
  int type;
  int stek_count;
  int count_string;
  double x;
  double step;
  int calk_to_pol_count;
  int stek_count_pol;
  int flag_error;  // 1 - деление на ноль, 2 - стек закончился, 3 - нет
                   // закрывающей скобки, 4 - нет открывающей скобки
};

double pol(char *str_in, double x, int *error, double step);
double getop(char *s, struct pars_format *g);  //  взятие аргумента из строки
int check_str(char *s, struct pars_format *g);
void str_in_str_for_str_to_pol(const char *str_in, char *s, double x);
void case_c_t(int *i, int *j, const char *str_in, char *s);
void case_s_K(int *i, int *j, const char *str_in, char *s);
void case_S_C_T(int *i, int *j, const char *str_in, char *s);
void case_N_L(int *i, int *j, const char *str_in, char *s);
void case_M(int *i, int *j, char *s);

int str_to_pol(char *str_in, char *str_pol, struct pars_format *g);  // парсер
void str_to_pol_switch_1(int *p, char *c, struct pars_format *g, int type,
                         double *stek, char *out);
void str_to_pol_switch_2(int *p, struct pars_format *g, int type, double *stek,
                         char *out);
void str_to_pol_switch_3(int *p, struct pars_format *g, int type, double *stek,
                         char *out);
void str_to_pol_switch_4(int *p, struct pars_format *g, int type, double *stek,
                         char *out);
void trigometria(int type, double *stek, struct pars_format *g, char *out);
void add_sub(int type, double *stek, struct pars_format *g, char *out);
void mul_div_mod(int type, double *stek, struct pars_format *g, char *out);
int check_true_str(char *str_in);
void check_true_str_bracket(int len_str, char *tmp, int *flag_error);
void check_true_str_bracket_error(int len_str, char *tmp, char *str_in,
                                  int *flag_error);
void case_add(struct pars_format *g, double *stek);
void case_minys(struct pars_format *g, double *stek);
void case_mul(struct pars_format *g, double *stek);
void case_del(struct pars_format *g, double *stek);
void case_step(struct pars_format *g, double *stek);
void case_mod(struct pars_format *g, double *stek);
void case_sqrt(struct pars_format *g, double *stek);
void case_cos(struct pars_format *g, double *stek, double step);
void case_sin(struct pars_format *g, double *stek, double step);
void case_tan(struct pars_format *g, double *stek, double step);
void case_acos(struct pars_format *g, double *stek, double step);
void case_asin(struct pars_format *g, double *stek, double step);
void case_atan(struct pars_format *g, double *stek, double step);
void case_ln(struct pars_format *g, double *stek);
void case_log10(struct pars_format *g, double *stek);
void case_U(struct pars_format *g, double *stek);
void pol_1_switch(int *p, char *s, double *stek, struct pars_format *g);
void pol_2_switch(int *p, double *stek, struct pars_format *g);
// SRC_S21_CALK_H_
#endif
