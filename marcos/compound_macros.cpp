#include "compound_macros.h"
/**
* @param packet     m1                  m2            m3              m4
* !             property_num    problem/request  uitily/security   problem macro
*                   m5      m6     m7      m8      m9
* ?                day    month   year    hour    minute
*                   m10      m11       m12
* *                 data    data       data
*/
std::string display_message(char* input_macro_message)
{
    char  property_num = input_macro_message[0];
    char  request_mode = input_macro_message[1];
    char  problem_type = input_macro_message[2];
    char  problem_macro = input_macro_message[3];
    char  hour = input_macro_message[7];
    char min = input_macro_message[8];
    std::string message_to_display;

    switch (request_mode)
    {
    case problem:
        /**
         * ? in case of property problem
         */
        message_to_display = "propety #" + char_display(property_num);//property number
        switch (problem_type)
        {
        case uitily:
            switch (problem_macro)
            {
                // problems
                /***********************************************/
                /*       gas case       */
                /***********************************************/
            case gas_problem:
                message_to_display += " Gas Leakage Detected";
                break;
                /*---------------------------------------------*/
            case gas_problem_cleared:
                message_to_display += " Gas Leakage Cleared";
                break;
                /***********************************************/
                /*       sewage case       */
                /***********************************************/
            case sewage_problem:
                message_to_display = "near " + message_to_display;
                message_to_display += " Sewage Overflow  Detected";
                break;
                /*---------------------------------------------*/
            case sewage_problem_cleared:
                message_to_display = "near " + message_to_display;
                message_to_display += " Sewage Overflow  cleared";
                break;
                /***********************************************/
                /*       water flow case       */
                /***********************************************/
                // send data
            case water_flow_data:
                break;
            }
            break;
        case security:
            switch (problem_macro)
            {
                /**************************
                 *  * security messages
                 * *********************/
                 /****************************************/
                 /*       ownner case       */
                 /****************************************/
            case Access_granted_Owner:
                message_to_display += " Access granted Owner";
                break;
            case wrong_access_trail_owner:
                message_to_display += " Wrong Access trial by Owner";
                break;
                /****************************************/
                /*       guest case       */
                /***************************************/
            case Access_granted_guest:
                message_to_display += " Access granted Guest";

                break;
            case Access_code_erased:
                message_to_display += " Access Code Erased";

                break;
            case wrong_access_trail_guest:
                message_to_display += " Wrong Access trial by Guest";
                break;
            case Leave_Guest:
                message_to_display += " Leave Guest";
                
                break;
                /****************************************/
                /*       break in decetion       */
                /****************************************/
                message_to_display = "Rail fence Sector #" + property_num;
            case Break_in_Detected:
                message_to_display += " Break-in Detected";
                break;
            case Break_in_secured:
                message_to_display += " Break-in Secured";
                break;
                /****************************************/
            }
            break;
        }
        break;
    case request:
        break;
    }
    message_to_display += " at time " + time_format(hour, min);
    message_to_display += endFlag;
    return message_to_display;
}



std::string time_format(char hour, char minutes)
{
    std::string time= hours_display(hour) + " : " + char_display(minutes);
   /*
   std::string time;
    time.push_back(int(hour));
    time += " : ";
    time.push_back(int(minutes));
    */
    return time;
}
std::string hours_display(char hour)
{
    switch (hour)
    {
    case 0x00:
          return "00";
    case 0x01:
        return "01";
    case 0x02:
        return "02";
    case 0x03:
        return "03";
    case 0x04:
        return "04";
    case 0x05:
        return "05";
    case 0x06:
        return "06";
    case 0x07:
        return "07";
    case 0x08:
        return "08";
    case 0x09:
        return "09";
    case 0x10:
        return "10";
    case 0x11:
        return "11";
    case 0x12:
        return "12";
    case 0x13:
        return "13";
    case 0x14:
        return "14";
    case 0x15:
        return "15";
    case 0x16:
        return "16";
    case 0x17:
        return "17";
    case 0x18:
        return "18";
    case 0x19:
        return "19";
    case 0x20:
        return "20";
    case 0x21:
        return "21";
    case 0x22:
        return "22";
    case 0x23:
        return "23";
    case 0x24:
        return "24";
    }
}

std::string char_display(char c)
{
    char unit  = '0'  ; // '0'
    char tenth = '0';
    for (char i = 0; i < c; i++)
    {
        unit++;
        if (unit > '9')
        {
            tenth += 1;
            unit = '0';
        }
    }
    std::string mes;
    mes.push_back(tenth);
    mes.push_back(unit);
    return mes;
}
