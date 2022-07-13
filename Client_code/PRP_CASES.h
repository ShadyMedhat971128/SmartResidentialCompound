#ifndef PRP_CASES_H
#define PRP_CASES_H
#include <SoftwareSerial.h>
#include <string>

#define property_num  '0'

//---states for the RFID-----//
/**************************
 *  * security messages
 * *********************/
#define default_case    'x' //"def"
 /****************************************/
 /*       ownner case       */
 /****************************************/
#define Access_granted_Owner        'o'
#define wrong_access_trail_owner    't'
#define Owner_left                  'y'
/****************************************/
 /*       gaurd case       */
 /****************************************/
#define Access_granted_guard        'j'
#define guard_left                  'z'
/****************************************/
/*       guest case       */
/***************************************/
#define Access_granted_guest        'g'
#define Access_code_erased          'e'
#define wrong_access_trail_guest    'w'
#define Leave_Guest                 'L'
/****************************************/
/*       problem cases       */
/****************************************/
#define gas_problem             'g'
#define gas_problem_cleared     'j'
#define sewage_problem          's'
#define sewage_problem_cleared  'c'
/****************************************/
/*       send data       */
/****************************************/
#define water_flow_data         'w'
/****************************************/
/*       break in decetion       */
/****************************************/
#define Break_in_Detected           'b'
#define Break_in_secured            's'
/*                         */
//---------------------------/
/**
* proto types
*/
void security_message (char * message,char state);    
void utility_message(char * message,char state);
void space_lines();
#endif
