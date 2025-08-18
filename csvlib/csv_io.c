/***************************************************************************
 * @file    csv_io.c
 * @brief   Declaration of functions and structures related to CSV file communication.
 * @details Provides definitions for APIs to read/write CSV files in key-value format,
 *          used across all MCAL modules.
 *          Enables access to or updates of simulated input/output data.
 * @version 1.0
 * @date    2025-08-18
 * @author  Nguyen Truong Giang
 ***************************************************************************/

#include "csv_io.h"
#include <string.h>
#include <stdlib.h>
#include <error.h>

/*****************************************************************************
 * @fn				- csv_getInt
 * @brief			- This function retrieves an integer value from a CSV file.
 * @param[in]		- const char* key: The key to search for in the CSV file.
 * @return			- The integer value associated with the key, or -1 if not found.
 *
 */
int CSV_getInt(const char *key)
{
    if (key == NULL) {
        fprintf(stderr, "csv_getInt: NULL key provided.\n");
        return ERROR;
    }

    FILE* file = fopen(CSV_PATH, "r");
    if (!file) {
        // print error message
        perror("Failed to open CSV file");
        return ERROR;
    }   

    // Buffer to hold each line read from the CSV file
    char line[BUFFER_SIZE];
    
    // Read each line from the CSV file
    while (fgets(line, sizeof(line), file)) 
    {
        char line_copy[BUFFER_SIZE];
        strncpy(line_copy, line, sizeof(line_copy));
        line_copy[sizeof(line_copy) - 1] = '\0'; // Ensure null termination

        char* token_key = strtok(line_copy, ",");
        char* token_value = strtok(NULL, "\n");
        
        if (token_key && token_value && strcmp(token_key, key) == 0) 
        {
            char* endptr;
            errno = 0; // Reset errno before strtol
            long value = strtol(token_value, &endptr, 10);
            if (errno != 0 || endptr == token_value || *endptr != '\0') {
                fprintf(stderr, "Invalid integer value for key '%s': %s\n", key, token_value);
                fclose(file);
                return -1;
            }
            fclose(file);
            return (int)value;
        }
    }
    // Key was not found
    fclose(file);
    fprintf(stderr, "Key '%s' not found in CSV file.\n", key);
    return ERROR;
}


/*****************************************************************************
 * @fn				- csv_getString
 * @brief			- This function retrieves a string from a CSV file.
 * @param[in]		- const char* key: The key to search for in the CSV file.
 * @return			- The string associated with the key, or -1 if not found.
 */
char* CSV_getString(const char *key)
{
    if (key == NULL) {
        fprintf(stderr, "csv_getString: NULL key provided.\n");
        return NULL;
    }

    FILE* file = fopen(CSV_PATH, "r");
    if (!file) {
        // print error message
        perror("Failed to open CSV file");
        return NULL;
    }   

    // Buffer to hold each line read from the CSV file
    char line[BUFFER_SIZE];
    
    // Read each line from the CSV file
    while (fgets(line, sizeof(line), file)) 
    {
        char line_copy[BUFFER_SIZE];
        strncpy(line_copy, line, sizeof(line_copy));
        line_copy[sizeof(line_copy) - 1] = '\0'; // Ensure null termination

        char* token_key = strtok(line_copy, ",");
        char* token_value = strtok(NULL, "\n");
        
        if (token_key && token_value && strcmp(token_key, key) == 0) 
        {
            char *string_value= (char *)malloc(strlen(token_value) + 1);
            if(!string_value)
            {
                perror("Failed to allocate dynamic memory");
                return NULL;
            }
            strncpy(string_value , token_value, strlen(token_value));
            string_value[strlen(token_value)] = '\0';

            if (!string_value) {
                fprintf(stderr, "Invalid integer value for key '%s': %s\n", key, token_value);
                fclose(file);
                return NULL;
            }
            fclose(file);
            return string_value;
        }
    }
    // Key was not found
    fclose(file);
    fprintf(stderr, "Key '%s' not found in CSV file.\n", key);
    return NULL;
}

/*****************************************************************************
 * @fn				- csv_setInt
 * @brief			- This function set an int value from a CSV file.
 * @param[in]		- const char* key: The key to search for in the CSV file.
 *                  - int value: The value to set into the CSV file.
 * @return			- Non-return.
 */
void CSV_setInt(const char *key, int value)
{
    if (key == NULL) {
        fprintf(stderr, "csv_setInt: NULL key provided.\n");
    }

    FILE* file = fopen(CSV_PATH, "r");
    if (!file) {
        // print error message
        perror("Failed to open CSV file");
        fclose(file);
        file=NULL;
    }   

    int isFound =0;
    // Buffer to hold each line read from the CSV file
    char line[512];
    char *array[10][2];
    int index=0;
    
    // Read each line from the CSV file
    while (fgets(line, sizeof(line), file)) 
    {
        char line_copy[512];
        strncpy(line_copy, line, sizeof(line_copy));
        line_copy[sizeof(line_copy) - 1] = '\0'; // Ensure null termination

        char* token_key = strtok(line_copy, ",");
        char* token_value = strtok(NULL, "\n");
        if (token_key && token_value) 
        {
            array[index][0] = malloc(strlen(token_key) + 1);
            strcpy(array[index][0], token_key);
        
            array[index][1] = malloc(strlen(token_value) + 1);
            strcpy(array[index][1], token_value);
        }
        if(strcmp(token_key,key)==0)
        {
           sprintf(array[index][1],"%d",value);
           isFound=1;
        }
        index++;
    }
    fclose(file);
    
    FILE* new_file = fopen(CSV_PATH, "w");
    if (!new_file) {
        perror("Failed to open CSV file");
        fclose(new_file);
        new_file=NULL;
    }   
    for(int i=0;i<index;i++)
    {
        fprintf(new_file,"%s,%s\n",array[i][0],array[i][1]);
    }
    if(isFound == 0)
    {
        fprintf(stderr, "Key '%s' not found in CSV file.\n", key);
    }
    fclose(new_file);
    for (int i = 0; i < index; ++i) 
    {
        free(array[i][0]);
        free(array[i][1]);
    }
}