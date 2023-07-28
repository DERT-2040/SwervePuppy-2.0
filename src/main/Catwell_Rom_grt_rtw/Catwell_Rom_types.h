/*
 * Catwell_Rom_types.h
 *
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * Code generation for model "Catwell_Rom".
 *
 * Model version              : 1.10
 * Simulink Coder version : 9.9 (R2023a) 19-Nov-2022
 * C source code generated on : Fri Jul 14 20:38:59 2023
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Catwell_Rom_types_h_
#define RTW_HEADER_Catwell_Rom_types_h_
#include "rtwtypes.h"
#ifndef struct_tag_BlgwLpgj2bjudmbmVKWwDE
#define struct_tag_BlgwLpgj2bjudmbmVKWwDE

struct tag_BlgwLpgj2bjudmbmVKWwDE
{
  uint32_T f1[8];
};

#endif                                 /* struct_tag_BlgwLpgj2bjudmbmVKWwDE */

#ifndef typedef_cell_wrap_Catwell_Rom_T
#define typedef_cell_wrap_Catwell_Rom_T

typedef struct tag_BlgwLpgj2bjudmbmVKWwDE cell_wrap_Catwell_Rom_T;

#endif                                 /* typedef_cell_wrap_Catwell_Rom_T */

#ifndef struct_emxArray_real_T_10x1
#define struct_emxArray_real_T_10x1

struct emxArray_real_T_10x1
{
  real_T data[10];
  int32_T size[2];
};

#endif                                 /* struct_emxArray_real_T_10x1 */

#ifndef typedef_emxArray_real_T_10x1_Catwell__T
#define typedef_emxArray_real_T_10x1_Catwell__T

typedef struct emxArray_real_T_10x1 emxArray_real_T_10x1_Catwell__T;

#endif                             /* typedef_emxArray_real_T_10x1_Catwell__T */

#ifndef struct_emxArray_real_T
#define struct_emxArray_real_T

struct emxArray_real_T
{
  real_T *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
};

#endif                                 /* struct_emxArray_real_T */

#ifndef typedef_emxArray_real_T_Catwell_Rom_T
#define typedef_emxArray_real_T_Catwell_Rom_T

typedef struct emxArray_real_T emxArray_real_T_Catwell_Rom_T;

#endif                               /* typedef_emxArray_real_T_Catwell_Rom_T */

#ifndef struct_tag_luuwhq6dGSow7W8XwOuC3E
#define struct_tag_luuwhq6dGSow7W8XwOuC3E

struct tag_luuwhq6dGSow7W8XwOuC3E
{
  int32_T isInitialized;
  cell_wrap_Catwell_Rom_T inputVarSize[2];
  boolean_T CacheInputSizes;
  emxArray_real_T_Catwell_Rom_T *RefPosesInternal;
  emxArray_real_T_Catwell_Rom_T *RefDirectionsInternal;
  real_T LastPosesOutput[30];
  real_T LastDirectionsOutput[10];
};

#endif                                 /* struct_tag_luuwhq6dGSow7W8XwOuC3E */

#ifndef typedef_driving_internal_planning_Pat_T
#define typedef_driving_internal_planning_Pat_T

typedef struct tag_luuwhq6dGSow7W8XwOuC3E driving_internal_planning_Pat_T;

#endif                             /* typedef_driving_internal_planning_Pat_T */

/* Parameters (default storage) */
typedef struct P_Catwell_Rom_T_ P_Catwell_Rom_T;

/* Forward declaration for rtModel */
typedef struct tag_RTM_Catwell_Rom_T RT_MODEL_Catwell_Rom_T;

#endif                                 /* RTW_HEADER_Catwell_Rom_types_h_ */
