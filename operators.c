#include <stdio.h> //package stdio.h = standard "io", input and output

int main()
{
    /* (Description)
    This program converts an annual salary into hourly wage.
    */
    float salary;
    salary = 92005.00; //in $/yr

    /* Convert annual salary into dollars into hour */
    float wage;
    wage = salary/(40*50); /*Assumes 40 hours a week and 2 weeks vacation (50 weeks)*/

    printf("Your wage is $%.2f/hr\n", wage);
    printf("Your original salary was $%.2f/yr\n\n\n", salary);


    /*
    This program deals with the Tour de France
    Converting metric kilometer into US customary mile
    */

    float kilo;
    kilo = 55.446; //km/hr

    //Conversion of km into mile
    float mile;
    mile = kilo/1.6094; //Conversion factor 1.69094 km/mile

    printf("The top speed in the US is %.2f mph\n", mile);
    printf("The top speed LITERALLY EVERYWHERE ELSE IN THE WORLD is %.2f kmph\n\n", kilo);


    /*
    This program looks at vaccine efficacy
    Efficacy (n): the ability to produce the intended use or desired result.
    */

    int attacked_unvaccinated;
    attacked_unvaccinated = 6500; // amount of people attacked that are unvaccinated

    int attacked_vaccinated;
    attacked_vaccinated = 1500; // amount of people attacked that are vaccinated

    float vaccine_efficacy;
    vaccine_efficacy = ((attacked_unvaccinated - attacked_vaccinated)*1.0/attacked_unvaccinated)*100; //Added 1.0 to bring in the float int mathematics

    printf("The vaccine efficacy is %.2f%%\n", vaccine_efficacy); // double %% allows to print a %
    printf("The attack rate of unvaccinated people %d people\n\n", attacked_unvaccinated);

}
