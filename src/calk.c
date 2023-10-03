
#include "calk.h"

void case_add(struct pars_format *g, double *stek) {
  if (g->stek_count_pol >= 2) {
    double tmp_1 = 0;
    double tmp_2 = 0;
    tmp_1 = stek[g->stek_count_pol - 1];
    stek[g->stek_count_pol - 1] = 0.0;
    tmp_2 = stek[g->stek_count_pol - 2];
    stek[g->stek_count_pol - 2] = 0.0;
    stek[g->stek_count_pol - 2] = tmp_1 + tmp_2;
    g->stek_count_pol = g->stek_count_pol - 1;
  } else {
    g->flag_error = 20;
  }
}

void case_minys(struct pars_format *g, double *stek) {
  double tmp_1 = 0;
  double tmp_2 = 0;
  if (g->stek_count_pol >= 2) {
    tmp_1 = stek[g->stek_count_pol - 1] * (-1);
    stek[g->stek_count_pol - 1] = 0.0;
    tmp_2 = stek[g->stek_count_pol - 2];
    stek[g->stek_count_pol - 2] = 0.0;
    stek[g->stek_count_pol - 2] = tmp_2 + tmp_1;
    g->stek_count_pol = g->stek_count_pol - 1;
  } else {
    g->flag_error = 20;
  }
}

void case_mul(struct pars_format *g, double *stek) {
  double tmp_1 = 0;
  double tmp_2 = 0;
  if (g->stek_count_pol >= 2) {
    tmp_1 = stek[g->stek_count_pol - 1];
    stek[g->stek_count_pol - 1] = 0.0;
    tmp_2 = stek[g->stek_count_pol - 2];
    stek[g->stek_count_pol - 2] = 0.0;
    stek[g->stek_count_pol - 2] = tmp_1 * tmp_2;
    g->stek_count_pol = g->stek_count_pol - 1;
  } else {
    g->flag_error = 20;
  }
}

void case_del(struct pars_format *g, double *stek) {
  double tmp_1 = 0;
  double tmp_2 = 0;
  if (g->stek_count_pol >= 2) {
    tmp_1 = stek[g->stek_count_pol - 1];
    stek[g->stek_count_pol - 1] = 0.0;
    tmp_2 = stek[g->stek_count_pol - 2];
    stek[g->stek_count_pol - 2] = 0.0;
    if (tmp_1 != 0) {
      stek[g->stek_count_pol - 2] = tmp_2 / tmp_1;
    } else if (tmp_2 != 0) {
      g->flag_error = 10;
    } else {
      g->flag_error = 9;
    }
    g->stek_count_pol = g->stek_count_pol - 1;
  } else {
    g->flag_error = 20;
  }
}

void case_step(struct pars_format *g, double *stek) {
  double tmp_1 = 0;
  double tmp_2 = 0;
  if (g->stek_count_pol >= 2) {
    tmp_1 = stek[g->stek_count_pol - 1];
    stek[g->stek_count_pol - 1] = 0.0;
    tmp_2 = stek[g->stek_count_pol - 2];
    stek[g->stek_count_pol - 2] = 0.0;
    stek[g->stek_count_pol - 2] = pow(tmp_2, tmp_1);
    g->stek_count_pol = g->stek_count_pol - 1;
  } else {
    g->flag_error = 20;
  }
}

void case_mod(struct pars_format *g, double *stek) {
  double tmp_1 = 0;
  double tmp_2 = 0;
  if (g->stek_count_pol >= 2) {
    tmp_1 = stek[g->stek_count_pol - 1];
    stek[g->stek_count_pol - 1] = 0.0;
    tmp_2 = stek[g->stek_count_pol - 2];
    stek[g->stek_count_pol - 2] = 0.0;
    if (tmp_1 != 0) {
      stek[g->stek_count_pol - 2] = fmod(tmp_2, tmp_1);
    } else if (tmp_2 != 0) {
      g->flag_error = 10;
    } else {
      g->flag_error = 9;
    }
    g->stek_count_pol = g->stek_count_pol - 1;
  } else {
    g->flag_error = 20;
  }
}

void case_sqrt(struct pars_format *g, double *stek) {
  double tmp_1 = 0;
  if (g->stek_count_pol >= 1) {
    tmp_1 = stek[g->stek_count_pol - 1];
    if (tmp_1 > 0) {
      stek[g->stek_count_pol - 1] = sqrt(tmp_1);
    } else {
      g->flag_error = 10;  //  корень из отрицательного числа
    }
  } else {
    g->flag_error = 20;
  }
}

void case_cos(struct pars_format *g, double *stek, double step) {
  double tmp_1 = 0;
  if (g->stek_count_pol >= 1) {
    tmp_1 = stek[g->stek_count_pol - 1];
    if ((fabs(cos(tmp_1)) > step)) {
      stek[g->stek_count_pol - 1] = cos(tmp_1);
    } else {
      g->flag_error = 10;
    }
  } else {
    g->flag_error = 20;
  }
}

void case_sin(struct pars_format *g, double *stek, double step) {
  double tmp_1 = 0;
  if (g->stek_count_pol >= 1) {
    tmp_1 = stek[g->stek_count_pol - 1];
    if ((fabs(sin(tmp_1)) > step)) {
      stek[g->stek_count_pol - 1] = sin(tmp_1);
    } else {
      g->flag_error = 10;
    }
  } else {
    g->flag_error = 10;
  }
}

void case_tan(struct pars_format *g, double *stek, double step) {
  double tmp_1 = 0;
  if (g->stek_count_pol >= 1) {
    tmp_1 = stek[g->stek_count_pol - 1];
    if (!(fabs(cos(tmp_1)) < step) && !(fabs(tan(tmp_1)) < step)) {
      stek[g->stek_count_pol - 1] = tan(tmp_1);
    } else {
      g->flag_error = 10;
    }
  } else {
    g->flag_error = 20;
  }
}

void case_acos(struct pars_format *g, double *stek, double step) {
  double tmp_1 = 0;
  if (g->stek_count_pol >= 1) {
    tmp_1 = stek[g->stek_count_pol - 1];
    if ((fabs(acos(tmp_1)) > step)) {
      stek[g->stek_count_pol - 1] = acos(tmp_1);
    } else {
      g->flag_error = 10;
    }
  } else {
    g->flag_error = 20;
  }
}

void case_asin(struct pars_format *g, double *stek, double step) {
  double tmp_1 = 0;
  if (g->stek_count_pol >= 1) {
    tmp_1 = stek[g->stek_count_pol - 1];
    if ((fabs(asin(tmp_1)) > step)) {
      stek[g->stek_count_pol - 1] = asin(tmp_1);
    } else {
      g->flag_error = 10;
    }
  } else {
    g->flag_error = 20;
  }
}

void case_atan(struct pars_format *g, double *stek, double step) {
  double tmp_1 = 0;
  if (g->stek_count_pol >= 1) {
    tmp_1 = stek[g->stek_count_pol - 1];
    if ((fabs(atan(tmp_1)) > step)) {
      stek[g->stek_count_pol - 1] = atan(tmp_1);
    } else {
      g->flag_error = 10;
    }
  } else {
    g->flag_error = 20;
  }
};

void case_ln(struct pars_format *g, double *stek) {
  double tmp_1 = 0;
  if (g->stek_count_pol >= 1) {
    tmp_1 = stek[g->stek_count_pol - 1];
    stek[g->stek_count_pol - 1] = log(tmp_1);
  } else {
    g->flag_error = 20;
  }
};

void case_log10(struct pars_format *g, double *stek) {
  double tmp_1 = 0;
  if (g->stek_count_pol >= 1) {
    tmp_1 = stek[g->stek_count_pol - 1];
    stek[g->stek_count_pol - 1] = log10(tmp_1);
  } else {
    g->flag_error = 20;
  }
};

void case_U(struct pars_format *g, double *stek) {
  double tmp_1 = 0;
  if (g->stek_count_pol >= 1) {
    tmp_1 = stek[g->stek_count_pol - 1];
    stek[g->stek_count_pol - 1] = tmp_1 * (-1);
  } else {
    g->flag_error = 20;
  }
}

int check_true_str(char *str_in) {
  char s_for_pol[512] = "\0";
  double x = 1;
  int len_str = 0;
  int flag_error = 0;
  len_str = strlen(str_in);
  char tmp[512] = "\0";
  str_in_str_for_str_to_pol(str_in, s_for_pol, x);
  strcpy(tmp, str_in);
  check_true_str_bracket(len_str, tmp, &flag_error);
  check_true_str_bracket_error(len_str, tmp, str_in, &flag_error);
  return flag_error;
}

void check_true_str_bracket(int len_str, char *tmp, int *flag_error) {
  int count = 0;
  int count_bracket_open = 0;
  int count_bracket_close = 0;
  while (count < len_str) {
    if (tmp[count] == '(') {
      count_bracket_open++;
    }
    if (tmp[count] == ')') {
      count_bracket_close++;
    }
    count++;
  }
  count = 0;
  if (count_bracket_open > count_bracket_close) {
    *flag_error = 3;
  } else if (count_bracket_open < count_bracket_close) {
    *flag_error = 4;
  }
}

void check_true_str_bracket_error(int len_str, char *tmp, char *str_in,
                                  int *flag_error) {
  int count = 0;
  if (tmp[count] == '-' && count == 0) {
    str_in[count] = 'U';
    count++;
  }
  while (count < len_str && *flag_error == 0) {
    if (tmp[count] == '(' && tmp[count + 1] == '-') {
      str_in[count] = '(';
      str_in[count + 1] = 'U';
      count = count + 2;
    }
    if ((tmp[count] == '/' || tmp[count] == '*' || tmp[count] == '+' ||
         tmp[count] == '-' || tmp[count] == 's' || tmp[count] == 'c' ||
         tmp[count] == 't' || tmp[count] == 'S' || tmp[count] == 'C' ||
         tmp[count] == 'T' || tmp[count] == 't' || tmp[count] == 'm' ||
         tmp[count] == '^' || tmp[count] == 'K' || tmp[count] == 'N' ||
         tmp[count] == 'L') &&
        (tmp[count + 1] == '/' || tmp[count + 1] == '*' ||
         tmp[count + 1] == '+' || tmp[count + 1] == '-' ||
         tmp[count + 1] == '^')) {
      *flag_error = 5;
    }
    if ((tmp[count] == '(') &&
        (tmp[count + 1] == '/' || tmp[count + 1] == '*' ||
         tmp[count + 1] == '+' || tmp[count + 1] == '^' ||
         tmp[count + 1] == 'K')) {
      *flag_error = 6;  // знак за скабкой
    }
    if ((tmp[count] == '.') && (tmp[count + 1] == '.')) {
      *flag_error = 7;
    }
    if ((tmp[count] == 'x') && (tmp[count + 1] == 'x')) {
      *flag_error = 8;
    }
    tmp[count] = str_in[count];
    count++;
  }
}

void mul_div_mod(int type, double *stek, struct pars_format *g, char *out) {
  char simvol = type;
  int flag_prioriti = 0;
  if (g->stek_count == 0) {
    stek[g->stek_count] = simvol;
    g->stek_count = g->stek_count + 1;
  } else if (stek[g->stek_count - 1] == '+' || stek[g->stek_count - 1] == '-') {
    stek[g->stek_count] = simvol;
    g->stek_count = g->stek_count + 1;
  } else if (stek[g->stek_count - 1] == '/' || stek[g->stek_count - 1] == '*' ||
             stek[g->stek_count - 1] == 's' || stek[g->stek_count - 1] == 'c' ||
             stek[g->stek_count - 1] == 't' || stek[g->stek_count - 1] == 'S' ||
             stek[g->stek_count - 1] == 'C' || stek[g->stek_count - 1] == 'T' ||
             stek[g->stek_count - 1] == 't' || stek[g->stek_count - 1] == 'm' ||
             stek[g->stek_count - 1] == '^' || stek[g->stek_count - 1] == 'K' ||
             stek[g->stek_count - 1] == 'N' || stek[g->stek_count - 1] == 'L' ||
             stek[g->stek_count - 1] == 'U') {
    flag_prioriti = 1;
    while (flag_prioriti == 1) {
      g->stek_count = g->stek_count - 1;
      out[g->count_string] = stek[g->stek_count];
      stek[g->stek_count] = 0;
      g->count_string = g->count_string + 1;
      out[g->count_string] = ' ';
      g->count_string = g->count_string + 1;
      if (g->stek_count != 0 &&
          (stek[g->stek_count - 1] == '/' || stek[g->stek_count - 1] == '*' ||
           stek[g->stek_count - 1] == 's' || stek[g->stek_count - 1] == 'c' ||
           stek[g->stek_count - 1] == 't' || stek[g->stek_count - 1] == 'S' ||
           stek[g->stek_count - 1] == 'C' || stek[g->stek_count - 1] == 'T' ||
           stek[g->stek_count - 1] == 't' || stek[g->stek_count - 1] == 'm' ||
           stek[g->stek_count - 1] == '^' || stek[g->stek_count - 1] == 'K' ||
           stek[g->stek_count - 1] == 'N' || stek[g->stek_count - 1] == 'L' ||
           stek[g->stek_count - 1] == 'U')) {
        flag_prioriti = 1;
      } else {
        flag_prioriti = 0;  // out while
        stek[g->stek_count] = simvol;
        g->stek_count = g->stek_count + 1;
      }
    }
  } else if (stek[g->stek_count - 1] == '(') {
    stek[g->stek_count] = simvol;
    g->stek_count = g->stek_count + 1;
  }
}

void add_sub(int type, double *stek, struct pars_format *g, char *out) {
  char simvol = type;
  int flag_prioriti = 0;
  if (g->stek_count == 0) {
    stek[g->stek_count] = simvol;
    g->stek_count = g->stek_count + 1;
  } else if (stek[g->stek_count - 1] == '/' || stek[g->stek_count - 1] == '*' ||
             stek[g->stek_count - 1] == '+' || stek[g->stek_count - 1] == '-' ||
             stek[g->stek_count - 1] == 's' || stek[g->stek_count - 1] == 'c' ||
             stek[g->stek_count - 1] == 't' || stek[g->stek_count - 1] == 'S' ||
             stek[g->stek_count - 1] == 'C' || stek[g->stek_count - 1] == 'T' ||
             stek[g->stek_count - 1] == 't' || stek[g->stek_count - 1] == 'm' ||
             stek[g->stek_count - 1] == '^' || stek[g->stek_count - 1] == 'K' ||
             stek[g->stek_count - 1] == 'N' || stek[g->stek_count - 1] == 'L' ||
             stek[g->stek_count - 1] == 'U') {
    flag_prioriti = 1;
    while (flag_prioriti == 1) {
      g->stek_count = g->stek_count - 1;
      out[g->count_string] = stek[g->stek_count];
      stek[g->stek_count] = 0;
      g->count_string = g->count_string + 1;
      out[g->count_string] = ' ';
      g->count_string = g->count_string + 1;
      if (g->stek_count != 0 &&
          (stek[g->stek_count - 1] == '/' || stek[g->stek_count - 1] == '*' ||
           stek[g->stek_count - 1] == '+' || stek[g->stek_count - 1] == '-' ||
           stek[g->stek_count - 1] == 's' || stek[g->stek_count - 1] == 'c' ||
           stek[g->stek_count - 1] == 't' || stek[g->stek_count - 1] == 'S' ||
           stek[g->stek_count - 1] == 'C' || stek[g->stek_count - 1] == 'T' ||
           stek[g->stek_count - 1] == 't' || stek[g->stek_count - 1] == 'm' ||
           stek[g->stek_count - 1] == '^' || stek[g->stek_count - 1] == 'K' ||
           stek[g->stek_count - 1] == 'N' || stek[g->stek_count - 1] == 'L' ||
           stek[g->stek_count - 1] == 'U')) {
        flag_prioriti = 1;
      } else {
        flag_prioriti = 0;  // out while
        stek[g->stek_count] = simvol;
        g->stek_count = g->stek_count + 1;
      }
    }
  } else if (stek[g->stek_count - 1] == '(') {
    stek[g->stek_count] = simvol;
    g->stek_count = g->stek_count + 1;
  }
};

void trigometria(int type, double *stek, struct pars_format *g, char *out) {
  char simvol = type;
  int flag_prioriti = 0;
  if (g->stek_count == 0) {
    stek[g->stek_count] = simvol;
    g->stek_count = g->stek_count + 1;
  } else if (stek[g->stek_count - 1] == 's' || stek[g->stek_count - 1] == 'c' ||
             stek[g->stek_count - 1] == 't' || stek[g->stek_count - 1] == 'S' ||
             stek[g->stek_count - 1] == 'C' || stek[g->stek_count - 1] == 'T' ||
             stek[g->stek_count - 1] == 't' || stek[g->stek_count - 1] == 'm' ||
             stek[g->stek_count - 1] == '^' || stek[g->stek_count - 1] == 'K' ||
             stek[g->stek_count - 1] == 'N' || stek[g->stek_count - 1] == 'L' ||
             stek[g->stek_count - 1] == 'U') {
    flag_prioriti = 1;
    while (flag_prioriti == 1) {
      g->stek_count = g->stek_count - 1;
      out[g->count_string] = stek[g->stek_count];
      stek[g->stek_count] = 0;
      g->count_string = g->count_string + 1;
      out[g->count_string] = ' ';
      g->count_string = g->count_string + 1;
      if (g->stek_count != 0 &&
          (stek[g->stek_count - 1] == 's' || stek[g->stek_count - 1] == 'c' ||
           stek[g->stek_count - 1] == 't' || stek[g->stek_count - 1] == 'S' ||
           stek[g->stek_count - 1] == 'C' || stek[g->stek_count - 1] == 'T' ||
           stek[g->stek_count - 1] == 't' || stek[g->stek_count - 1] == 'm' ||
           stek[g->stek_count - 1] == '^' || stek[g->stek_count - 1] == 'K' ||
           stek[g->stek_count - 1] == 'N' || stek[g->stek_count - 1] == 'L' ||
           stek[g->stek_count - 1] == 'U')) {
        flag_prioriti = 1;
      } else {
        flag_prioriti = 0;  // out while
        stek[g->stek_count] = simvol;
        g->stek_count = g->stek_count + 1;
      }
    }
  } else if (stek[g->stek_count - 1] == '(') {
    stek[g->stek_count] = simvol;
    g->stek_count = g->stek_count + 1;
  } else {
    stek[g->stek_count] = simvol;
    g->stek_count = g->stek_count + 1;
  }
}

void str_in_str_for_str_to_pol(const char *str_in, char *s, double x) {
  int p = 0;
  int i = 0;
  int j = 0;
  int tmp_i = 0;
  char str_x[64] = "\0";
  p = strlen(str_in);
  while (i < p) {
    if (str_in[i] == 'c' || str_in[i] == 't') {
      case_c_t(&i, &j, str_in, s);
    } else if (str_in[i] == 's') {
      case_s_K(&i, &j, str_in, s);
    } else if (str_in[i] == 'a') {
      case_S_C_T(&i, &j, str_in, s);
    } else if (str_in[i] == 'l') {
      case_N_L(&i, &j, str_in, s);
    } else if (str_in[i] == 'm') {
      case_M(&i, &j, s);
    } else if (str_in[i] == 'x') {
      sprintf(str_x, "%lf", x);
      s[j] = '(';
      j++;
      while (str_x[tmp_i] != '\0' && tmp_i <= 63) {
        s[j] = str_x[tmp_i];
        j++;
        tmp_i++;
      }
      s[j] = ')';
      j++;
      tmp_i = 0;
      i++;
    } else {
      s[j] = str_in[i];  // просто  перекладываем
      j++;
      i++;
    }
  }
}

void case_c_t(int *i, int *j, const char *str_in, char *s) {
  if (str_in[*i] == 'c') {
    s[*j] = 'c';  // cos
    *j = *j + 1;
    *i = *i + 3;
  } else {
    s[*j] = 't';  // tan
    *j = *j + 1;
    *i = *i + 3;
  }
}

void case_s_K(int *i, int *j, const char *str_in, char *s) {
  if (str_in[*i + 1] == 'i') {
    s[*j] = 's';  // sin
    *j = *j + 1;
    *i = *i + 3;
  } else {
    s[*j] = 'K';  // sqrt
    *j = *j + 1;
    *i = *i + 4;
  }
}

void case_S_C_T(int *i, int *j, const char *str_in, char *s) {
  if (str_in[*i + 1] == 's') {
    s[*j] = 'S';
    *j = *j + 1;
    *i = *i + 4;  // asin
  }
  if (str_in[*i + 1] == 'c') {
    s[*j] = 'C';  // acos
    *j = *j + 1;
    *i = *i + 4;
  }
  if (str_in[*i + 1] == 't') {
    s[*j] = 'T';  // atan
    *j = *j + 1;
    *i = *i + 4;
  }
}

void case_N_L(int *i, int *j, const char *str_in, char *s) {
  if (str_in[*i + 1] == 'n') {
    s[*j] = 'N';
    *j = *j + 1;
    *i = *i + 2;  // ln
  } else {
    s[*j] = 'L';
    *j = *j + 1;
    *i = *i + 5;  // log10
  }
}

void case_M(int *i, int *j, char *s) {
  s[*j] = 'm';
  *j = *j + 1;
  *i = *i + 3;  // mod
}

int check_str(char *s, struct pars_format *g) {
  int number = -1;
  if (!(isdigit(s[g->count])) && s[g->count] != '.') {
    number = s[g->count];  //  не  число
  }
  if (isdigit(s[g->count])) {
    number = 0;
  }
  return number;
}

double getop(char *s, struct pars_format *g) {
  double x = 0;
  double y = 0;
  double n = 0.1;
  if (s[g->count] == ' ') {
    g->count = g->count + 1;
  }
  if (isdigit(s[g->count])) {
    while (isdigit(s[g->count])) {
      x = x * 10 + (s[g->count] - 48);
      g->count = g->count + 1;
    };  // накопление целой части
  }
  if (s[g->count] == '.') {
    g->count = g->count + 1;
    if (isdigit(s[g->count])) {
      while (isdigit(s[g->count])) {
        y = y + (s[g->count] - 48) * n;
        n = n * 0.1;
        g->count = g->count + 1;
      };  // накопление дробной части
      if (s[g->count] == '.') {
        g->flag_error = 20;
      }
    }
  }
  x = x + y;
  return x;
}

int str_to_pol(char *c, char *out, struct pars_format *g) {
  int tmp_p = 0;
  int len_str = strlen(c);
  double stek[100] = {0};
  g->count_string = 0;
  g->stek_count = 0;
  g->count = 0;
  int p = 0;
  int type = 0;
  g->count = p;
  while (p < len_str && g->flag_error == 0) {
    tmp_p = p;
    type = check_str(c, g);
    str_to_pol_switch_1(&p, c, g, type, stek, out);
    str_to_pol_switch_2(&p, g, type, stek, out);
    str_to_pol_switch_3(&p, g, type, stek, out);
    str_to_pol_switch_4(&p, g, type, stek, out);
    if (tmp_p == p) {
      g->flag_error = 20;
    }
  }
  while (g->stek_count > 0) {
    g->stek_count = g->stek_count - 1;
    out[g->count_string] = stek[g->stek_count];
    stek[g->stek_count] = 0;
    g->count_string = g->count_string + 1;
    out[g->count_string] = ' ';
    g->count_string = g->count_string + 1;
  }
  return 0;
};

void str_to_pol_switch_1(int *p, char *c, struct pars_format *g, int type,
                         double *stek, char *out) {
  double tmp = 0;
  int i = 0;
  char tmp_str[164] = "\0";
  switch (type) {
    case 0:  // кладем в аутпут значения
      tmp = getop(c, g);
      *p = g->count;
      sprintf(tmp_str, "%lf", tmp);
      while (tmp_str[i] != '\0') {
        out[g->count_string] = tmp_str[i];
        g->count_string = g->count_string + 1;
        i++;
      }
      i = 0;
      for (int o = 0; o < 163; o++) {
        tmp_str[o] = '\0';
      }
      out[g->count_string] = ' ';
      g->count_string = g->count_string + 1;
      ;
      break;
    case '+':
      add_sub(type, stek, g, out);
      *p = *p + 1;
      g->count = *p;
      break;
    case '-':
      add_sub(type, stek, g, out);
      *p = *p + 1;
      g->count = *p;
      break;
    case '*':
      mul_div_mod(type, stek, g, out);
      *p = *p + 1;
      g->count = *p;
      break;
    default:
      break;
  }
}

void str_to_pol_switch_2(int *p, struct pars_format *g, int type, double *stek,
                         char *out) {
  int flag_prioriti = 0;
  switch (type) {
    case '(':
      stek[g->stek_count] = '(';
      g->stek_count = g->stek_count + 1;
      *p = *p + 1;
      g->count = *p;
      break;
    case ')':
      if (g->stek_count > 0 && stek[g->stek_count - 1] != '(') {
        flag_prioriti = 1;
        while (flag_prioriti == 1) {
          g->stek_count = g->stek_count - 1;
          out[g->count_string] = stek[g->stek_count];
          stek[g->stek_count] = 0;
          g->count_string = g->count_string + 1;
          out[g->count_string] = ' ';
          g->count_string = g->count_string + 1;
          if (g->stek_count != 0 && stek[g->stek_count - 1] != '(') {
            flag_prioriti = 1;
          } else if (g->stek_count != 0 && stek[g->stek_count - 1] == '(') {
            g->stek_count = g->stek_count - 1;
            stek[g->stek_count] = 0;
            flag_prioriti = 0;
          } else if (g->stek_count == 0) {
            flag_prioriti = 0;
          }
        }
      } else if (g->stek_count != 0 && stek[g->stek_count - 1] == '(') {
        g->stek_count = g->stek_count - 1;
        stek[g->stek_count] = 0;
      }
      *p = *p + 1;
      g->count = *p;
      break;
    default:
      break;
  }
}

void str_to_pol_switch_3(int *p, struct pars_format *g, int type, double *stek,
                         char *out) {
  switch (type) {
    case '/':
      mul_div_mod(type, stek, g, out);
      *p = *p + 1;
      g->count = *p;
      break;
    case 's':
      trigometria(type, stek, g, out);
      *p = *p + 1;
      g->count = *p;
      break;
    case 'c':
      trigometria(type, stek, g, out);
      *p = *p + 1;
      g->count = *p;
      break;
    case 't':
      trigometria(type, stek, g, out);
      *p = *p + 1;
      g->count = *p;
      break;
    case 'S':
      trigometria(type, stek, g, out);
      *p = *p + 1;
      g->count = *p;
      break;
    case 'C':
      trigometria(type, stek, g, out);
      *p = *p + 1;
      g->count = *p;
      break;
    case 'T':
      trigometria(type, stek, g, out);
      *p = *p + 1;
      g->count = *p;
      break;
    default:
      break;
  }
}

void str_to_pol_switch_4(int *p, struct pars_format *g, int type, double *stek,
                         char *out) {
  switch (type) {
    case 'm':
      mul_div_mod(type, stek, g, out);
      *p = *p + 1;
      g->count = *p;
      break;
    case '^':
      trigometria(type, stek, g, out);
      *p = *p + 1;
      g->count = *p;
      break;
    case 'U':
      trigometria(type, stek, g, out);
      *p = *p + 1;
      g->count = *p;
      break;
    case 'K':
      trigometria(type, stek, g, out);
      *p = *p + 1;
      g->count = *p;
      break;
    case 'N':
      trigometria(type, stek, g, out);
      *p = *p + 1;
      g->count = *p;
      break;
    case 'L':
      trigometria(type, stek, g, out);
      *p = *p + 1;
      g->count = *p;
      break;
    default:
      break;
  }
}

double pol(char *str_in, double x, int *error, double step) {
  char s[512] = "\0";
  char s_for_pol[512] = "\0";
  struct pars_format g = {0};
  g.x = x;
  str_in_str_for_str_to_pol(str_in, s_for_pol, x);
  check_true_str(s_for_pol);
  str_to_pol(s_for_pol, s, &g);
  g.count = 0;
  double stek[100] = {0};
  // double tmp = 0;
  g.stek_count_pol = 0;
  int type = 0;
  g.type = 0;
  int p = 0;
  int len_str = 0;
  g.step = step;
  if (step > 0.1) {
    step = 0.1;
  }
  len_str = strlen(s);
  while (p < len_str && g.flag_error == 0) {
    g.count = p;
    type = check_str(s, &g);
    g.type = type;
    pol_1_switch(&p, s, stek, &g);
    pol_2_switch(&p, stek, &g);
  }
  double result = stek[0];
  *error = g.flag_error;
  return result;
}

void pol_1_switch(int *p, char *s, double *stek, struct pars_format *g) {
  double tmp;
  switch (g->type) {
    case ' ':
      *p = *p + 1;
      break;
    case 0:
      tmp = getop(s, g);
      stek[g->stek_count_pol] = tmp;
      g->stek_count_pol = g->stek_count_pol + 1;
      *p = g->count;
      break;
    case '+':
      case_add(g, stek);
      *p = *p + 2;
      break;
    case '*':
      case_mul(g, stek);
      *p = *p + 2;
      break;
    case '/':
      case_del(g, stek);
      *p = *p + 2;
      break;
    case '-':
      case_minys(g, stek);
      *p = *p + 2;
      break;
    case '^':
      case_step(g, stek);
      *p = *p + 2;
      break;
    case 'm':
      case_mod(g, stek);
      *p = *p + 2;
      break;
    case 'c':
      case_cos(g, stek, g->step);
      *p = *p + 2;
      break;
    default:
      break;
  }
}

void pol_2_switch(int *p, double *stek, struct pars_format *g) {
  switch (g->type) {
    case 's':
      case_sin(g, stek, g->step);
      *p = *p + 2;
      break;
    case 't':
      case_tan(g, stek, g->step);
      *p = *p + 2;
      break;
    case 'C':
      case_acos(g, stek, g->step);
      *p = *p + 2;
      break;
    case 'S':
      case_asin(g, stek, g->step);
      *p = *p + 2;
      break;
    case 'T':
      case_atan(g, stek, g->step);
      *p = *p + 2;
      break;
    case 'K':
      case_sqrt(g, stek);
      *p = *p + 2;
      break;
    case 'N':
      case_ln(g, stek);
      *p = *p + 2;
      break;
    case 'L':
      case_log10(g, stek);
      *p = *p + 2;
      break;
    case 'U':
      case_U(g, stek);
      *p = *p + 2;
      break;
    default:
      break;
  }
}
