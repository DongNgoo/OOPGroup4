/*/////////////////////////////////////////////////////////////////////////
                        Assignment 1 - Milestone 3
Full Name  : Dong Ngo
Student ID#: 129342233
Email      : dngo1@myseneca.ca
Section    : ZAA

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <ctype.h>
#include <string.h>

// include the user library "core" so we can use those functions
#include "core.h"
// include the user library "clinic" where the function prototypes are declared
#include "clinic.h"




//////////////////////////////////////
// DISPLAY FUNCTIONS
//////////////////////////////////////

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Display's the patient table header (table format)
void displayPatientTableHeader(void)
{
    printf("Pat.# Name            Phone#\n"
           "----- --------------- --------------------\n");
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Displays a single patient record in FMT_FORM | FMT_TABLE format
void displayPatientData(const struct Patient* patient, int fmt)
{
    if (fmt == FMT_FORM)
    {
        printf("Name  : %s\n"
               "Number: %05d\n"
               "Phone : ", patient->name, patient->patientNumber);
        displayFormattedPhone(patient->phone.number);
        printf(" (%s)\n", patient->phone.description);
    }
    else
    {
        printf("%05d %-15s ", patient->patientNumber,
               patient->name);
        displayFormattedPhone(patient->phone.number);
        printf(" (%s)\n", patient->phone.description);
    }
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Display's appointment schedule headers (date-specific or all records)
void displayScheduleTableHeader(const struct Date* date, int isAllRecords)
{
    printf("Clinic Appointments for the Date: ");

    if (isAllRecords)
    {
        printf("<ALL>\n\n");
        printf("Date       Time  Pat.# Name            Phone#\n"
               "---------- ----- ----- --------------- --------------------\n");
    }
    else
    {
        printf("%04d-%02d-%02d\n\n", date->year, date->month, date->day);
        printf("Time  Pat.# Name            Phone#\n"
               "----- ----- --------------- --------------------\n");
    }
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Display a single appointment record with patient info. in tabular format
void displayScheduleData(const struct Patient* patient,
                         const struct Appointment* appoint,
                         int includeDateField)
{
    if (includeDateField)
    {
        printf("%04d-%02d-%02d ", appoint->date.year, appoint->date.month,
               appoint->date.day);
    }
    printf("%02d:%02d %05d %-15s ", appoint->time.hour, appoint->time.min,
           patient->patientNumber, patient->name);

    displayFormattedPhone(patient->phone.number);

    printf(" (%s)\n", patient->phone.description);
}


//////////////////////////////////////
// MENU & ITEM SELECTION FUNCTIONS
//////////////////////////////////////

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// main menu
void menuMain(struct ClinicData* data)
{
    int selection;

    do {
        printf("Veterinary Clinic System\n"
               "=========================\n"
               "1) PATIENT     Management\n"
               "2) APPOINTMENT Management\n"
               "-------------------------\n"
               "0) Exit System\n"
               "-------------------------\n"
               "Selection: ");
        selection = inputIntRange(0, 2);
        putchar('\n');
        switch (selection)
        {
        case 0:
            printf("Are you sure you want to exit? (y|n): ");
            selection = !(inputCharOption("yn") == 'y');
            putchar('\n');
            if (!selection)
            {
                printf("Exiting system... Goodbye.\n\n");
            }
            break;
        case 1:
            menuPatient(data->patients, data->maxPatient);
            break;
        case 2:
            menuAppointment(data);
            break;
        }
    } while (selection);
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Menu: Patient Management
void menuPatient(struct Patient patient[], int max)
{
    int selection;

    do {
        printf("Patient Management\n"
               "=========================\n"
               "1) VIEW   Patient Data\n"
               "2) SEARCH Patients\n"
               "3) ADD    Patient\n"
               "4) EDIT   Patient\n"
               "5) REMOVE Patient\n"
               "-------------------------\n"
               "0) Previous menu\n"
               "-------------------------\n"
               "Selection: ");
        selection = inputIntRange(0, 5);
        putchar('\n');
        switch (selection)
        {
        case 1:
            displayAllPatients(patient, max, FMT_TABLE);
            suspend();
            break;
        case 2:
            searchPatientData(patient, max);
            break;
        case 3:
            addPatient(patient, max);
            suspend();
            break;
        case 4:
            editPatient(patient, max);
            break;
        case 5:
            removePatient(patient, max);
            suspend();
            break;
        }
    } while (selection);
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Menu: Patient edit
void menuPatientEdit(struct Patient* patient)
{
    int selection;

    do {
        printf("Edit Patient (%05d)\n"
               "=========================\n"
               "1) NAME : %s\n"
               "2) PHONE: ", patient->patientNumber, patient->name);
        
        displayFormattedPhone(patient->phone.number);
        
        printf("\n"
               "-------------------------\n"
               "0) Previous menu\n"
               "-------------------------\n"
               "Selection: ");
        selection = inputIntRange(0, 2);
        putchar('\n');

        if (selection == 1)
        {
            printf("Name  : ");
            inputCString(patient->name, 1, NAME_LEN);
            putchar('\n');
            printf("Patient record updated!\n\n");
        }
        else if (selection == 2)
        {
            inputPhoneData(&patient->phone);
            printf("Patient record updated!\n\n");
        }

    } while (selection);
}


// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Menu: Appointment Management
void menuAppointment(struct ClinicData* data)
{
    int selection;

    do {
        printf("Appointment Management\n"
               "==============================\n"
               "1) VIEW   ALL Appointments\n"
               "2) VIEW   Appointments by DATE\n"
               "3) ADD    Appointment\n"
               "4) REMOVE Appointment\n"
               "------------------------------\n"
               "0) Previous menu\n"
               "------------------------------\n"
               "Selection: ");
        selection = inputIntRange(0, 4);
        putchar('\n');
        switch (selection)
        {
        case 1:
            viewAllAppointments(data);  // ToDo: You will need to create this function!
            suspend();
            break;
        case 2:
            viewAppointmentSchedule(data);  // ToDo: You will need to create this function!
            suspend();
            break;
        case 3:
            addAppointment(data->appointments, data->maxAppointments,
                           data->patients, data->maxPatient);  // ToDo: You will need to create this function!
            suspend();
            break;
        case 4:
            removeAppointment(data->appointments, data->maxAppointments,
                              data->patients, data->maxPatient);  // ToDo: You will need to create this function!
            suspend();
            break;
        }
    } while (selection);
}


// ---------------------------------------------------------------------------
// !!! INSERT/COPY YOUR MS#2 FUNCTION DEFINITIONS BELOW... !!!
// Note: Maintain the same order/sequence as it is listed in the header file
//       Properly organize/categorize any new functions accordingly
// ---------------------------------------------------------------------------


// Display's all patient data in the FMT_FORM | FMT_TABLE format
// (Copy your code from MS#2)
void displayAllPatients(const struct Patient patient[], int max, int fmt)
{

    int i, recordPatient;
    recordPatient = 0;
    displayPatientTableHeader();
    for (i = 0; i < max; i++)
    {
        if (patient[i].patientNumber != 0)
        {
            displayPatientData(&patient[i], FMT_TABLE);
            recordPatient++;
        }
        if (recordPatient == 0)
        {
            printf("*** No records found ***\n");
        }

    }
    printf("\n");

}

// Search for a patient record based on patient number or phone number
// (Copy your code from MS#2)
void searchPatientData(const struct Patient patient[], int max)
{
    int inputSelection, previousMenu = 0;
    do
    {
        
        printf("Search Options\n");
        printf("==========================\n");
        printf("1) By patient number\n");
        printf("2) By phone number\n");
        printf("..........................\n");
        printf("0) Previous menu\n");
        printf("..........................\n");
        printf("Selection: ");
        inputSelection = inputIntRange(0, 2);

        if (inputSelection == 1)
        {
            printf("\n");
            searchPatientByPatientNumber(patient, max);
            printf("\n");
            suspend();

        }
        else if (inputSelection == 2)
        {
            printf("\n");
            searchPatientByPhoneNumber(patient, max);
            printf("\n");
            suspend();

        }
        else if (inputSelection == 0)
        {
            previousMenu = 1;
            printf("\n");
        }
    } while (!previousMenu);


}

// Add a new patient record to the patient array
// (Copy your code from MS#2)
void addPatient(struct Patient patient[], int max)
{
    int i, valid = 0;
    for (i = 0; i < max && !valid; ++i)
    {
        if (patient[i].patientNumber == 0)
        {
            valid = 1;


            patient[i].patientNumber = nextPatientNumber(patient, max);
            inputPatient(&patient[i]);

            printf("*** New patient record added ***\n\n");
            
        }
    }

    if (!valid)
    {
        printf("ERROR: Patient listing is FULL!\n\n");
    }

}

// Edit a patient record from the patient array
// (Copy your code from MS#2)
void editPatient(struct Patient patient[], int max)
{
    int inputEditPatientNumber, index;
    index = 0;
    printf("Enter the patient number: ");
    inputEditPatientNumber = inputIntPositive();
    index = findPatientIndexByPatientNum(inputEditPatientNumber, patient, max);
    printf("\n");
    if (index != -1)
    {

        menuPatientEdit(&patient[index]);
    }
    else if (index == -1)
    {

        printf("ERROR: Patient record not found!\n");
    }
  
}

// Remove a patient record from the patient array
// (Copy your code from MS#2)
void removePatient(struct Patient patient[], int max)
{
    struct Patient empty = { 0 };
    int inputRemovePatientNumber, i, index;
    index = 0;
    char removeDecision;
    printf("Enter the patient number: ");
    inputRemovePatientNumber = inputIntPositive();
    index = findPatientIndexByPatientNum(inputRemovePatientNumber, patient, max);
    printf("\n");

    if (index != -1)
    {

        displayPatientData(&patient[index], FMT_FORM);
        printf("\n");
        printf("Are you sure you want to remove this patient record? (y/n): ");

        removeDecision = inputCharOption("yn");

        if (removeDecision == 'y')
        {
            for (i = 0; i < max; i++)
            {
                patient[index] = empty;
            }
            printf("Patient record has been removed!\n\n");

        }
        else
        {
            printf("Operation aborted.\n\n");
        }

    }
    else if (index == -1)
    {
        printf("ERROR: Patient record not found!\n\n");
    }

}

// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// Milestone #3 mandatory functions...
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

// View ALL scheduled appointments
void viewAllAppointments(const struct ClinicData* data)
{
    int i, j;
    
  
    displayScheduleTableHeader(&data->appointments->date, DISPLAY);

 
       
  
   
        sortDateTime(data->appointments, data->maxAppointments);
  
    
    for (i = 0; i < data->maxAppointments; i++)
    {
        for (j = 0; j < data->maxPatient; j++)
        {
            if (data->appointments[i].patientNumber == data->patients[j].patientNumber)
            {
                displayScheduleData(&data->patients[j], &data->appointments[i], DISPLAY);
            }
        }
      
        
    }

    printf("\n");


}

// View appointment schedule for the user input date
void viewAppointmentSchedule(const struct ClinicData* appointments)
{
    int i, j;
    struct Date date = { 0 };
    inputDate(&date.year, &date.month, &date.day);
    printf("\n");
    
    
    displayScheduleTableHeader(&date, NO_DISPLAY);
    sortDateTime(appointments->appointments, appointments->maxAppointments);
    for (i = 0; i < appointments->maxAppointments; ++i)
    {
        for (j = 0; j < appointments->maxPatient; ++j)
        {
            if (appointments->appointments[i].patientNumber == appointments->patients[j].patientNumber)
            {
                
                if (appointments->appointments[i].date.year == date.year && appointments->appointments[i].date.month == date.month 
                    && appointments->appointments[i].date.day == date.day)
                {
                    displayScheduleData(&appointments->patients[j], &appointments->appointments[i], NO_DISPLAY);
                }
            }
        }
    }
    putchar('\n');
}

// Add an appointment record to the appointment array
void addAppointment(struct Appointment appoints[], int maxAppointments, struct Patient patients[], int maxPatient)
{
    struct Appointment dateTime = { 0 };
    int i, valid = 0;
    int inputPatientNum;
    
        
        printf("Patient Number: ");
        inputPatientNum = inputIntPositive();
        for (i = 0; i < maxPatient && !valid; i++)
        {
            if (patients[i].patientNumber == inputPatientNum)
            {
                
                valid = 1;
                
            }
           
        }
        if (!valid)
        {
            printf("\n");
            printf("ERROR: Patient record not found!\n\n");
        }

        else 
        {
            do
            {
                inputDate(&dateTime.date.year, &dateTime.date.month, &dateTime.date.day);
                inputTime(&dateTime.time.hour, &dateTime.time.min);

                    valid = 1;

                    for (i = 0; i < maxAppointments && valid; i++)
                    {

                        if (compareDateTime(&dateTime, &appoints[i]) == 0)
                        {

                            valid = 0;
                            
                        }
                        
                    }
                   
                    
                    if (!valid)
                    {
                        printf("\n");
                        printf("ERROR: Appointment timeslot is not available!\n\n");
                    }
                
            } while (!valid);


            for (i = 0; i < maxAppointments && valid; i++)
            {
                if (appoints[i].patientNumber < 1)
                {
                    appoints[i].patientNumber = inputPatientNum;
                   
                    appoints[i].date = dateTime.date;
                    appoints[i].time = dateTime.time;
                    
                    
                    valid = 0;
                }
                
            }
            
            printf("\n");
            printf("*** Appointment scheduled! ***\n\n");

        }
        

}

// Remove an appointment record from the appointment array
void removeAppointment(struct Appointment appointments[], int maxAppointment, struct Patient patients[], int maxPatient)
{
    struct Appointment dateTime = { 0 };
    struct Appointment empty = { 0 };
    int inputRemoveAppointment, i, index, validAppointmentInput = 0;
    index = 0;
    char removeDecision;
   
        printf("Patient Number: ");
        
        inputRemoveAppointment = inputIntPositive();

        index = findPatientIndexByPatientNum(inputRemoveAppointment, patients, maxPatient);
       
        if (index != -1)
        {
            do
            {
        
            inputDate(&dateTime.date.year, &dateTime.date.month, &dateTime.date.day);
            
            
           
                for (i = 0; i < maxAppointment && !validAppointmentInput; i++)
                {
                    if (compareDate(&dateTime.date, &appointments[i].date) == 0)
                    {

                        validAppointmentInput = 1;

                    }
                }
                if (!validAppointmentInput)
                {
                    printf("ERROR: Patient record not found!\n");
                }
            } while (!validAppointmentInput);
            printf("\n");
            displayPatientData(&patients[index], FMT_FORM);
            printf("Are you sure you want to remove this appointment (y,n): ");
            removeDecision = inputCharOption("yn");
            if (removeDecision == 'y')
            {

                for (i = 0; i < maxAppointment && validAppointmentInput; i++)
                {
                    if (compareDate(&dateTime.date, &appointments[i].date) == 0 && appointments[i].patientNumber == inputRemoveAppointment)
                    {
                       
                        appointments[i] = empty;
                        validAppointmentInput = 0;
                        
                    }
                }
                printf("\n");
                printf("Appointment record has been removed!\n\n");
            }
            else
            {
                printf("Operation aborted.\n\n");
            }
        }

        else if (index == -1)
        {

            printf("ERROR: Patient record not found!\n\n");
            validAppointmentInput = 0;
           
            
        }
        
       
}

//////////////////////////////////////
// UTILITY FUNCTIONS
//////////////////////////////////////

// Search and display patient record by patient number (form)
// (Copy your code from MS#2)
void searchPatientByPatientNumber(const struct Patient patient[], int max)
{
    int searchPatientNum, index;
    index = -1;
    printf("Search by patient number: ");
    searchPatientNum = inputIntPositive();

    index = findPatientIndexByPatientNum(searchPatientNum, patient, max);
    printf("\n");
    if (index != -1)
    {

        displayPatientData(&patient[index], FMT_FORM);

    }
    else if (index == -1)
    {
        printf("*** No records found ***\n");

    }

}

// Search and display patient records by phone number (tabular)
// (Copy your code from MS#2)
void searchPatientByPhoneNumber(const struct Patient patient[], int max)
{
    int i, validPhone;
    validPhone = 0;
    char phoneInput[PHONE_LEN + 1] = { 0 };
    printf("Search by phone number: ");
    inputCString(phoneInput, 1, PHONE_LEN);
    printf("\n");
    displayPatientTableHeader();
    for (i = 0; i < max; i++)
    {

        if (strcmp(patient[i].phone.number, phoneInput) == 0)
        {
            displayPatientData(&patient[i], FMT_TABLE);
            validPhone = 1;
        }


    }
    if (!validPhone)
    {
        printf("\n");
        printf("*** No records found ***\n");

    }
}

// Get the next highest patient number
// (Copy your code from MS#2)
int nextPatientNumber(const struct Patient patient[], int max)
{

    int i, largestPatientNumber;
    largestPatientNumber = patient[0].patientNumber;
    for (i = 1; i < max; ++i) {
        if (patient[i].patientNumber > largestPatientNumber) {
            largestPatientNumber = patient[i].patientNumber;
        }
    }
    largestPatientNumber = largestPatientNumber + 1;
    return largestPatientNumber;

}

// Find the patient array index by patient number (returns -1 if not found)
// (Copy your code from MS#2)
int findPatientIndexByPatientNum(int patientNumber,
    const struct Patient patient[], int max)
{
    int i, validIndex;
    validIndex = 0;
    for (i = 0; i < max && !validIndex; i++)
    {
        if (patient[i].patientNumber == patientNumber)
        {
            patientNumber = i;
            
            validIndex = 1;
        }
        else
        {
            validIndex = 0;
        }


    }
    if (validIndex == 0)
    {
        patientNumber = -1;
    }
    return patientNumber;
}
//This function use for sort the date and time from low to high
void sortDateTime(struct Appointment* appoints, int max)
{
    int i, curPass, iterIdx;
    struct Appointment temp = { 0 };
   
    for (i = 0; i < max; i++)
    {
        curPass = i;
        for (iterIdx = i + 1; iterIdx < max; iterIdx++)
        {
            if (compareDateTime(&appoints[iterIdx], &appoints[curPass]) < 0)
            {
                curPass = iterIdx;
            }
        }
        if (curPass != i)
        {
            temp = appoints[i];
            appoints[i] = appoints[curPass];
            appoints[curPass] = temp;
        }
    }

}

//This fuction use to compare Date and time 
int compareDateTime(const struct Appointment* dt1, const struct Appointment* dt2)
{

    int date1 = dt1->date.year * 10000 + dt1->date.month * 100 + dt1->date.day;
    int date2 = dt2->date.year * 10000 + dt2->date.month * 100 + dt2->date.day;
    int time1 = (dt1->time.hour * 60) + dt1->time.min;
    int time2 = (dt2->time.hour * 60) + dt2->time.min;
    int result = 0;

    if (date1 > date2)
    {
        result = 1;
    }
    else if (date1 < date2)
    {
        result = -1;
    }
    else if (time1 < time2)
    {
        result = -1;
    }
    else if (time1 > time2)
    {
        result = 1;
    }

    return result;
}
//This function use for comparing date(year, month, day)
int compareDate(const struct Date* dt1, const struct Date* dt2)
{

    int date1 = dt1->year * 10000 + dt1->month * 100 + dt1->day;
    int date2 = dt2->year * 10000 + dt2->month * 100 + dt2->day;
    int result = 0;
    if (date1 > date2)
    {
        result = 1;
    }
    else if (date1 < date2)
    {
        result = -1;
    }

    return result;
}



//////////////////////////////////////
// USER INPUT FUNCTIONS
//////////////////////////////////////

// Get user input for a new patient record
// (Copy your code from MS#2)
void inputPatient(struct Patient* patient)
{
    printf("Patient Data Input\n");
    printf("------------------\n");
    printf("Number: %05d\n", patient->patientNumber);

    printf("Name  : ");
    inputCString(patient->name, 1, NAME_LEN);
    printf("\n");
    inputPhoneData(&patient->phone);


}

// Get user input for phone contact information
// (Copy your code from MS#2)
void inputPhoneData(struct Phone* phone)
{
    int phoneSelection;

    printf("Phone Information\n");
    printf("-----------------\n");
    printf("How will the patient like to be contacted?\n");
    printf("1. Cell\n"
        "2. Home\n"
        "3. Work\n"
        "4. TBD\n");
    printf("Selection: ");

    phoneSelection = inputIntRange(1, 4);

    printf("\n");
    if (phoneSelection == 1)
    {
        strcpy(phone->description, "CELL");



    }
    else if (phoneSelection == 2)
    {
        strcpy(phone->description, "HOME");

    }
    else if (phoneSelection == 3)
    {
        strcpy(phone->description, "WORK");

    }
    else if (phoneSelection == 4)
    {
        strcpy(phone->description, "TBD");

    }


    if (phoneSelection != 4)
    {
        printf("Contact: %s\n", phone->description);

        inputPhoneNumber(phone->number, PHONE_LEN, PHONE_LEN);

        printf("\n");


    }

}
//Get user input for year, month, day
void inputDate(int* year, int* month, int* day)
{
    int maxDay;
    printf("Year        : ");
    *year = inputIntPositive();
    printf("Month (%d-%d): ", MIN_MONTH, MAX_MONTH);
    *month = inputIntRange(MIN_MONTH,MAX_MONTH);
    if (*month == 2)
    {
        //leap year
        if ((*year % 4 == 0 && *year % 100 != 0) || *year % 400 == 0)
        {
            maxDay = 29;
        }
        else
        {
            maxDay = 28;
        }
    }
    else if (*month == 4 || *month == 6 || *month == 9 || *month == 11)
    {
        maxDay = 30;
    }
    else
    {
        maxDay = 31;
    }
    printf("Day (1-%d)  : ", maxDay);
    *day = inputIntRange(1, maxDay);

}
//Get user input for hour and minute
void inputTime(int* hour, int* minute)
{
    int  valid = 0;
    do
    {
    printf("Hour (0-23)  : ");
    *hour = inputIntRange(0, 23);
    printf("Minute (0-59): ");
    *minute = inputIntRange(0, 59);
    if (*hour < START_HOUR || *hour > END_HOUR)
    {
        valid = 0;
    }
    
    else
    {
        valid = 1;
        if (*minute % INTERVAL != 0)
        {
            valid = 0;
        }
        if ((*hour * 60) + *minute > (END_HOUR * 60))
        {
            valid = 0;
        }
        
    }
    
    if (valid == 0)
    {
        printf("ERROR: Time must be between %d:00 and %d:00 in %d minute intervals.\n\n", START_HOUR, END_HOUR, INTERVAL);
    }

} while (!valid);

}



//////////////////////////////////////
// FILE FUNCTIONS
//////////////////////////////////////

// Import patient data from file into a Patient array (returns # of records read)
int importPatients(const char* datafile, struct Patient patients[], int max)
{
   
    
    FILE* fp = fopen(datafile, "r");
    char tmpChar, tmpPhone[PHONE_LEN + 1] = { 0 };
    
    int i = 0, records = 0;
    if (fp != NULL)
    {
        while (i < max && fscanf(fp, "%d|%[^|]|%[^|]|", &patients[i].patientNumber,
            patients[i].name,
            patients[i].phone.description) == 3)
        {
            tmpChar = fgetc(fp);
            // No phone number!
            if (tmpChar == '\n')
            {
                patients[i].phone.number[0] = '\0';
                

            }
            else
            {

                if (fscanf(fp, "%9[^|]\n", tmpPhone) == 1)
                {
                    patients[i].phone.number[0] = tmpChar;
                    patients[i].phone.number[1] = '\0';
                    strcat(patients[i].phone.number, tmpPhone);
                }
                else
                {
                    while (fgetc(fp) != '\n');
                    strcpy(patients[i].phone.number, "*Error*");
                }
            }
            i++;
        }

        records = i;
      

        // clean up!
        fclose(fp);
        fp = NULL;

       
    }
    else
    {
        puts("ERROR: Unable to open file.");
    }
        
   return records;
    

 }

// Import appointment data from file into an Appointment array (returns # of records read)
int importAppointments(const char* datafile, struct Appointment appoints[], int max)
{
    FILE* fp = fopen(datafile, "r");
    int i = 0, records = 0;
    if (fp != NULL)
    {
        while (i < max && fscanf(fp, "%d,%d,%d,%d,%d,%d\n",
            &appoints[i].patientNumber,
            &appoints[i].date.year,
            &appoints[i].date.month,
            &appoints[i].date.day,
            &appoints[i].time.hour,
            &appoints[i].time.min) == 6)
        {
            i++;
        }
        records = i;
        fclose(fp);
        fp = NULL;

    }

    else

    {
        puts("Failed to open file for reading!\n");
    }
    return records;

}             