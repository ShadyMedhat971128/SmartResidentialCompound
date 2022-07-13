#include "PRP_CASES.h"

void security_message (char * message,char state){
  
  message[0] = property_num;//property number
  message[1]= 'p';             //proplem/request
  message[2]= 's';             //uitily /security 
switch (state)
  {
    //------------------------------------------------------//
    /* owner case */
    //------------------------------------------------------//
    case Access_granted_Owner :
      message [3]= Access_granted_Owner;
      break;
    case Owner_left   :
      message [3]= Owner_left ;
      break;
    case wrong_access_trail_owner :
      message [3]= wrong_access_trail_owner;
      break;
    //-------------------------------------------------------------------//
    /*          guest cases       */
    //------------------------------------------------------------------//
    case Access_granted_guest:
     message [3]= Access_granted_guest;
      break;
    case Leave_Guest   :
      message [3]= Leave_Guest;
      break;
    case wrong_access_trail_guest :
      message [3]= wrong_access_trail_guest;
      break;
    //-----------------------------------------------------------------------//
    /*        guard cases       */
     case guard_left :
    message [3]= guard_left;
      break;
    case Access_granted_guard :
     message [3]= Access_granted_guard;
      break;
   //----------------------------------------------------------------------------//
     case Access_code_erased   :
      //Serial.println("code_erased");
      message [3]= Access_code_erased ;
      break;
    /*  default case   */ 
    default:
    //return "";
      break;
  }
  if(state == default_case)
  {
    for(int i =0 ; i<12;i++)
    {
    message[i] ='0';
    }
  }
  else
  {
    // put date 
    int day ='7';
    int month ='5';
    int year ='2';
    message [4]= day;//day
     message [5]= month;//month
      message [6]= year;//year
    //put time
    int hour ='7';
    int minute = '5'; 
    message [7]= hour;//hour
    message [8]= minute;//minute
    //put extra data
    message [9]= '5';
    message [10]= '6';
    message [11]= '*';
  }
}
/**************************************************************************************/
void utility_message(char * message,char state)
{
  message[0] = property_num;             //property number
  message[1]=  'p' ;             //proplem/request
  //message[2]=  'u' ;             //uitily /security 
switch (state)
  {
    //------------------------------------------------------//
    /* gas problem */
    //------------------------------------------------------//
    case gas_problem  :
      message [2]= 'u';             //uitily /security
      message [3]= gas_problem;
      break;
    case gas_problem_cleared   :
      message [2] = 'u';             //uitily /security
      message [3] = gas_problem_cleared ;
      break;
    //-------------------------------------------------------------------//
    /*          sewage_problem       */
    //------------------------------------------------------------------//
    case sewage_problem:
     message [2] = 'u';             //uitily /security
     message [3] = sewage_problem;
     break;
    case sewage_problem_cleared   :
      message [2]= 'u';             //uitily /security
      message [3]= sewage_problem_cleared ;
      break;
    //-----------------------------------------------------------------------//
    /*        break in decetion       */
     
     case Break_in_Detected  :
     message [2]= 's';             //uitily /security
     message [3]= Break_in_Detected ;
      break;
//    case Break_in_secured :
//    message += String('s');             //uitily /security
//     message += String(Break_in_secured);
//      break;
   //----------------------------------------------------------------------------//
     /*  default case   */ 
    default:
    //return "";
      break;
  }
  if(state == default_case)
  {
    //return "";
  }
  else
  {
     // put date 
    int day ='7';
    int month ='5';
    int year ='2';
    message [4]= day;//day
     message [5]= month;//month
      message [6]= year;//year
    //put time
    int hour ='7';
    int minute = '5'; 
    message [7]= hour;//hour
    message [8]= minute;//minute
    //put extra data
    message [9]= '5';
    message [10]= '6';
    message [11]= '*';
  }
}
void space_lines()
{
  Serial.println("");
  Serial.println("//----------------------------------------------------------------------------//");
  Serial.println("");
  Serial.println("//----------------------------------------------------------------------------//");
  Serial.println("");
}
