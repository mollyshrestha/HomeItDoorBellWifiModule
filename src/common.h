#ifndef COMMON_H
#define COMMON_H

/****************************************************************************************************************************************************************\
* Type definition(s)
\****************************************************************************************************************************************************************/
typedef unsigned char       U1;
typedef unsigned short      U2;
typedef unsigned int        U4;
typedef unsigned long       L4;

typedef signed char         S1;
typedef signed short        S2;
typedef signed int          S4;

/****************************************************************************************************************************************************************\
* Macro definition(s)
\****************************************************************************************************************************************************************/
#define FAILURE                             (0)                                
#define SUCCESS                             (1)                               

#define ON                                  (1)                                 
#define OFF                                 (0)                               

#define HI                                  (1)                                 
#define LO                                  (0)                                

#define TRUE                                (1)                                
#define FALSE                               (0)                                

#define DISABLE                             (0)
#define ENABLE                              (~DISABLE)

#define BIT0                                (0x01)
#define BIT1                                (0x02)
#define BIT2                                (0x04)
#define BIT3                                (0x08)
#define BIT4                                (0x10)
#define BIT5                                (0x20)
#define BIT6                                (0x40)
#define BIT7                                (0x80)
#define BIT8                                (0x0100)
#define BIT9                                (0x0200)
#define BIT10                               (0x0400)
#define BIT11                               (0x0800)
#define BIT12                               (0x1000)
#define BIT13                               (0x2000)
#define BIT14                               (0x4000)
#define BIT15                               (0x8000)
#define BIT16                               (0x00010000)
#define BIT17                               (0x00020000)
#define BIT18                               (0x00040000)
#define BIT19                               (0x00080000)
#define BIT20                               (0x00100000)
#define BIT21                               (0x00200000)
#define BIT22                               (0x00400000)
#define BIT23                               (0x00800000)
#define BIT24                               (0x01000000)
#define BIT25                               (0x02000000)
#define BIT26                               (0x04000000)
#define BIT27                               (0x08000000)
#define BIT28                               (0x10000000)
#define BIT29                               (0x20000000)
#define BIT30                               (0x40000000)
#define BIT31                               (0x80000000)

#define BIT_U1                              (0xFF)                              
#define BIT_U2                              (0xFFFF)                       
#define BIT_U4                              (0xFFFFFFFF)                      

#define U1_MAX                              (0xFF)
#define U1_MIN                              (0x00)
#define S1_MAX                              (0x7F)
#define S1_MIN                              (0x80)
#define U2_MAX                              (0xFFFF)
#define U2_MIN                              (0x0000)
#define U4_MAX                              (0xFFFFFFFFu)
#define U4_MIN                              (0x00000000)
#define S2_MAX                              (0x7FFF)
#define S2_MIN                              (0x8000)
#define S4_MAX                              (0x7FFFFFFF)
#define S4_MIN                              (0x80000000)

#define N_1                                 (1)                                 /* [1]                          */
#define N_2                                 (2)                                 /* [2]                          */
#define N_3                                 (3)                                 /* [3]                          */
#define N_4                                 (4)                                 /* [4]                          */
#define N_5                                 (5)                                 /* [5]                          */
#define N_6                                 (6)                                 /* [6]                          */
#define N_7                                 (7)                                 /* [7]                          */
#define N_8                                 (8)                                 /* [8]                          */
#define N_9                                 (9)                                 /* [9]                          */
#define N_10                                (10)                                /* [10]                         */
#define N_11                                (11)                                /* [11]                         */
#define N_12                                (12)                                /* [12]                         */
#define N_13                                (13)                                /* [13]                         */
#define N_14                                (14)                                /* [14]                         */
#define N_15                                (15)                                /* [15]                         */
#define N_16                                (16)                                /* [16]                         */
#define N_17                                (17)                                /* [17]                         */
#define N_18                                (18)                                /* [18]                         */
#define N_19                                (19)                                /* [19]                         */
#define N_20                                (20)                                /* [20]                         */
#define N_21                                (21)                                /* [21]                         */
#define N_22                                (22)                                /* [22]                         */
#define N_23                                (23)                                /* [23]                         */
#define N_24                                (24)                                /* [24]                         */
#define N_25                                (25)                                /* [25]                         */
#define N_26                                (26)                                /* [26]                         */
#define N_27                                (27)                                /* [27]                         */
#define N_28                                (28)                                /* [28]                         */
#define N_29                                (29)                                /* [29]                         */
#define N_30                                (30)                                /* [30]                         */
#define N_31                                (31)                                /* [31]                         */
#define N_32                                (32)                                /* [32]                         */
#define N_33                                (33)                                /* [33]                         */
#define N_34                                (34)                                /* [34]                         */
#define N_35                                (35)                                /* [35]                         */
#define N_36                                (36)                                /* [36]                         */
#define N_37                                (37)                                /* [37]                         */
#define N_38                                (38)                                /* [38]                         */
#define N_39                                (39)                                /* [39]                         */
#define N_40                                (40)                                /* [40]                         */
#define N_41                                (41)                                /* [41]                         */
#define N_42                                (42)                                /* [42]                         */
#define N_43                                (43)                                /* [43]                         */
#define N_44                                (44)                                /* [44]                         */
#define N_45                                (45)                                /* [45]                         */
#define N_46                                (46)                                /* [46]                         */
#define N_47                                (47)                                /* [47]                         */
#define N_48                                (48)                                /* [48]                         */
#define N_49                                (49)                                /* [49]                         */
#define N_50                                (50)                                /* [50]                         */
#define N_51                                (51)                                /* [51]                         */
#define N_52                                (52)                                /* [52]                         */
#define N_53                                (53)                                /* [53]                         */
#define N_54                                (54)                                /* [54]                         */
#define N_55                                (55)                                /* [55]                         */
#define N_56                                (56)                                /* [56]                         */
#define N_57                                (57)                                /* [57]                         */
#define N_58                                (58)                                /* [58]                         */
#define N_59                                (59)                                /* [59]                         */
#define N_60                                (60)                                /* [60]                         */
#define N_61                                (61)                                /* [61]                         */
#define N_62                                (62)                                /* [62]                         */
#define N_63                                (63)                                /* [63]                         */
#define N_64                                (64)                                /* [64]                         */
#define N_65                                (65)                                /* [65]                         */
#define N_66                                (66)                                /* [66]                         */
#define N_67                                (67)                                /* [67]                         */
#define N_68                                (68)                                /* [68]                         */
#define N_69                                (69)                                /* [69]                         */
#define N_70                                (70)                                /* [70]                         */
#define N_71                                (71)                                /* [71]                         */
#define N_72                                (72)                                /* [72]                         */
#define N_73                                (73)                                /* [73]                         */
#define N_74                                (74)                                /* [74]                         */
#define N_75                                (75)                                /* [75]                         */
#define N_76                                (76)                                /* [76]                         */
#define N_77                                (77)                                /* [77]                         */
#define N_78                                (78)                                /* [78]                         */
#define N_79                                (79)                                /* [79]                         */
#define N_80                                (80)                                /* [80]                         */
#define N_81                                (81)                                /* [81]                         */
#define N_82                                (82)                                /* [82]                         */
#define N_83                                (83)                                /* [83]                         */
#define N_84                                (84)                                /* [84]                         */
#define N_85                                (85)                                /* [85]                         */
#define N_86                                (86)                                /* [86]                         */
#define N_87                                (87)                                /* [87]                         */
#define N_88                                (88)                                /* [88]                         */
#define N_89                                (89)                                /* [89]                         */
#define N_90                                (90)                                /* [90]                         */
#define N_91                                (91)                                /* [91]                         */
#define N_92                                (92)                                /* [92]                         */
#define N_93                                (93)                                /* [93]                         */
#define N_94                                (94)                                /* [94]                         */
#define N_95                                (95)                                /* [95]                         */
#define N_96                                (96)                                /* [96]                         */
#define N_97                                (97)                                /* [97]                         */
#define N_98                                (98)                                /* [98]                         */
#define N_99                                (99)                                /* [99]                         */
#define N_100                               (100)                               /* [100]                        */
 

#endif
