#ifndef COMPOUND_MACROS_H
#define COMPOUND_MACROS_H
#include <SoftwareSerial.h>
#include <string>

//packet 12=> bytes structure 
/**
* @param packet     m1                  m2            m3              m4
* !             property_num    problem/request  uitily/security   problem macro
*                   m5      m6     m7      m8      m9
* ?                day    month   year    hour    minute
*                   m10      m11       m12
* *                 data    data       data
*/
/**************************
 *  * problem / request
 * *********************/
#define    problem     'p'
#define    request     'r'
 /**************************
  *  * uitily/security
  * *********************/
#define uitily      'u'
#define security    's'    

  /**************************
   *  * properties
   *  ? write the property number in decmails
   * *********************/
#define property_1  0
#define property_2  1
#define gate        3

   /**************************
     *  * utility probelms
     * *********************/
     // problems
#define gas_problem             'g'
#define gas_problem_cleared     'j'
#define sewage_problem          's'
#define sewage_problem_cleared  'c'
// send data
#define water_flow_data         'w'

/**************************
 *  * security messages
 * *********************/
 /****************************************/
 /*       ownner case       */
 /****************************************/
#define Access_granted_Owner        'o'
#define wrong_access_trail_owner    't'
#define Owner_left                  'y'
/****************************************/
 /*       gaurd case       */
 /****************************************/
#define Access_granted_guard        'x'
#define guard_left                  'z'
/****************************************/
/*       guest case       */
/***************************************/
#define Access_granted_guest        'g'
#define Access_code_erased          'e'
#define wrong_access_trail_guest    'w'
#define Leave_Guest                 'L'
/****************************************/
/*       break in decetion       */
/****************************************/
#define Break_in_Detected           'b'
#define Break_in_secured            's'
/****************************************/
/**************************
 *  * other helping macros
 * *********************/
#define endFlag     ""     // can change accroding to the needed end flag

 /**************************
  *  * functions prototypes
  * *********************/
String display_message(char* input_macro_message);
String time_format(char hour, char minutes);
String char_display(char c);
String hours_display(char hour);
#endif
