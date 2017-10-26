/**********************************************************************/
/*   ____  ____                                                       */
/*  /   /\/   /                                                       */
/* /___/  \  /                                                        */
/* \   \   \/                                                       */
/*  \   \        Copyright (c) 2003-2009 Xilinx, Inc.                */
/*  /   /          All Right Reserved.                                 */
/* /---/   /\                                                         */
/* \   \  /  \                                                      */
/*  \___\/\___\                                                    */
/***********************************************************************/

/* This file is designed for use with ISim build 0x7708f090 */

#define XSI_HIDE_SYMBOL_SPEC true
#include "xsi.h"
#include <memory.h>
#ifdef __GNUC__
#include <stdlib.h>
#else
#include <malloc.h>
#define alloca _alloca
#endif
static const char *ng0 = "C:/CPE_users/TP_ELN2/Groupe D/BELALOUI-CHAVRET/Projet1/chronoscore/counterDec_4b_RE.vhd";
extern char *IEEE_P_2592010699;
extern char *IEEE_P_3620187407;

unsigned char ieee_p_2592010699_sub_1744673427_503743352(char *, char *, unsigned int , unsigned int );
char *ieee_p_3620187407_sub_436279890_3965413181(char *, char *, char *, char *, int );


static void work_a_3409679260_3212880686_p_0(char *t0)
{
    char t16[16];
    char *t1;
    char *t2;
    unsigned char t3;
    unsigned char t4;
    char *t5;
    char *t6;
    char *t7;
    char *t8;
    char *t9;
    char *t10;
    unsigned char t11;
    unsigned char t12;
    unsigned char t13;
    unsigned char t14;
    unsigned char t15;
    char *t17;
    int t18;
    unsigned int t19;
    unsigned char t20;
    char *t21;
    char *t22;
    char *t23;
    char *t24;
    char *t25;
    char *t26;
    unsigned int t27;

LAB0:    xsi_set_current_line(51, ng0);
    t1 = (t0 + 1192U);
    t2 = *((char **)t1);
    t3 = *((unsigned char *)t2);
    t4 = (t3 == (unsigned char)3);
    if (t4 != 0)
        goto LAB2;

LAB4:    t1 = (t0 + 1192U);
    t2 = *((char **)t1);
    t11 = *((unsigned char *)t2);
    t12 = (t11 == (unsigned char)2);
    if (t12 == 1)
        goto LAB10;

LAB11:    t4 = (unsigned char)0;

LAB12:    if (t4 == 1)
        goto LAB7;

LAB8:    t3 = (unsigned char)0;

LAB9:    if (t3 != 0)
        goto LAB5;

LAB6:
LAB3:    xsi_set_current_line(68, ng0);
    t1 = (t0 + 1832U);
    t2 = *((char **)t1);
    t1 = (t0 + 6720U);
    t5 = (t0 + 6764);
    t7 = (t16 + 0U);
    t8 = (t7 + 0U);
    *((int *)t8) = 0;
    t8 = (t7 + 4U);
    *((int *)t8) = 3;
    t8 = (t7 + 8U);
    *((int *)t8) = 1;
    t18 = (3 - 0);
    t19 = (t18 * 1);
    t19 = (t19 + 1);
    t8 = (t7 + 12U);
    *((unsigned int *)t8) = t19;
    t4 = ieee_std_logic_unsigned_equal_stdv_stdv(IEEE_P_3620187407, t2, t1, t5, t16);
    if (t4 == 1)
        goto LAB21;

LAB22:    t3 = (unsigned char)0;

LAB23:    if (t3 != 0)
        goto LAB18;

LAB20:    xsi_set_current_line(71, ng0);
    t1 = (t0 + 4144);
    t2 = (t1 + 56U);
    t5 = *((char **)t2);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    *((unsigned char *)t7) = (unsigned char)2;
    xsi_driver_first_trans_fast(t1);

LAB19:    t1 = (t0 + 3968);
    *((int *)t1) = 1;

LAB1:    return;
LAB2:    xsi_set_current_line(52, ng0);
    t1 = (t0 + 6752);
    t6 = (t0 + 4080);
    t7 = (t6 + 56U);
    t8 = *((char **)t7);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    memcpy(t10, t1, 4U);
    xsi_driver_first_trans_fast(t6);
    xsi_set_current_line(53, ng0);
    t1 = (t0 + 4144);
    t2 = (t1 + 56U);
    t5 = *((char **)t2);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    *((unsigned char *)t7) = (unsigned char)2;
    xsi_driver_first_trans_fast(t1);
    goto LAB3;

LAB5:    xsi_set_current_line(58, ng0);
    t5 = (t0 + 1832U);
    t7 = *((char **)t5);
    t5 = (t0 + 6720U);
    t8 = (t0 + 6756);
    t10 = (t16 + 0U);
    t17 = (t10 + 0U);
    *((int *)t17) = 0;
    t17 = (t10 + 4U);
    *((int *)t17) = 3;
    t17 = (t10 + 8U);
    *((int *)t17) = 1;
    t18 = (3 - 0);
    t19 = (t18 * 1);
    t19 = (t19 + 1);
    t17 = (t10 + 12U);
    *((unsigned int *)t17) = t19;
    t20 = ieee_std_logic_unsigned_equal_stdv_stdv(IEEE_P_3620187407, t7, t5, t8, t16);
    if (t20 != 0)
        goto LAB13;

LAB15:    xsi_set_current_line(63, ng0);
    t1 = (t0 + 1832U);
    t2 = *((char **)t1);
    t1 = (t0 + 6720U);
    t5 = ieee_p_3620187407_sub_436279890_3965413181(IEEE_P_3620187407, t16, t2, t1, 1);
    t6 = (t16 + 12U);
    t19 = *((unsigned int *)t6);
    t27 = (1U * t19);
    t3 = (4U != t27);
    if (t3 == 1)
        goto LAB16;

LAB17:    t7 = (t0 + 4080);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    t10 = (t9 + 56U);
    t17 = *((char **)t10);
    memcpy(t17, t5, 4U);
    xsi_driver_first_trans_fast(t7);

LAB14:    goto LAB3;

LAB7:    t5 = (t0 + 1032U);
    t6 = *((char **)t5);
    t14 = *((unsigned char *)t6);
    t15 = (t14 == (unsigned char)3);
    t3 = t15;
    goto LAB9;

LAB10:    t1 = (t0 + 1312U);
    t13 = ieee_p_2592010699_sub_1744673427_503743352(IEEE_P_2592010699, t1, 0U, 0U);
    t4 = t13;
    goto LAB12;

LAB13:    xsi_set_current_line(59, ng0);
    t17 = (t0 + 6760);
    t22 = (t0 + 4080);
    t23 = (t22 + 56U);
    t24 = *((char **)t23);
    t25 = (t24 + 56U);
    t26 = *((char **)t25);
    memcpy(t26, t17, 4U);
    xsi_driver_first_trans_fast(t22);
    goto LAB14;

LAB16:    xsi_size_not_matching(4U, t27, 0);
    goto LAB17;

LAB18:    xsi_set_current_line(69, ng0);
    t8 = (t0 + 4144);
    t10 = (t8 + 56U);
    t17 = *((char **)t10);
    t21 = (t17 + 56U);
    t22 = *((char **)t21);
    *((unsigned char *)t22) = (unsigned char)3;
    xsi_driver_first_trans_fast(t8);
    goto LAB19;

LAB21:    t8 = (t0 + 1032U);
    t9 = *((char **)t8);
    t11 = *((unsigned char *)t9);
    t12 = (t11 == (unsigned char)3);
    t3 = t12;
    goto LAB23;

}

static void work_a_3409679260_3212880686_p_1(char *t0)
{
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;

LAB0:    xsi_set_current_line(78, ng0);

LAB3:    t1 = (t0 + 1832U);
    t2 = *((char **)t1);
    t1 = (t0 + 4208);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    memcpy(t6, t2, 4U);
    xsi_driver_first_trans_fast_port(t1);

LAB2:    t7 = (t0 + 3984);
    *((int *)t7) = 1;

LAB1:    return;
LAB4:    goto LAB2;

}

static void work_a_3409679260_3212880686_p_2(char *t0)
{
    char *t1;
    char *t2;
    unsigned char t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    char *t8;

LAB0:    xsi_set_current_line(79, ng0);

LAB3:    t1 = (t0 + 1992U);
    t2 = *((char **)t1);
    t3 = *((unsigned char *)t2);
    t1 = (t0 + 4272);
    t4 = (t1 + 56U);
    t5 = *((char **)t4);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    *((unsigned char *)t7) = t3;
    xsi_driver_first_trans_fast_port(t1);

LAB2:    t8 = (t0 + 4000);
    *((int *)t8) = 1;

LAB1:    return;
LAB4:    goto LAB2;

}


extern void work_a_3409679260_3212880686_init()
{
	static char *pe[] = {(void *)work_a_3409679260_3212880686_p_0,(void *)work_a_3409679260_3212880686_p_1,(void *)work_a_3409679260_3212880686_p_2};
	xsi_register_didat("work_a_3409679260_3212880686", "isim/chronometer_tb_isim_beh.exe.sim/work/a_3409679260_3212880686.didat");
	xsi_register_executes(pe);
}
