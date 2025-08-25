#include <stdio.h>
#include <math.h>
#include <windows.h>

int main()
{
	SetConsoleOutputCP(CP_UTF8);
	#define heart printf("\nLifetime\n\u2665\u2665\u2665\u2665\u2665\u2665\u2665\u2665:    ");
	
    printf("Enter the amount of hours:\n");
    float hours;
    scanf("%f", &hours);
	
    const float data1 = 8760.0; // hours in 1 year
    const float data2 = 730.0; // hours in 1 month
    const float data3 = 12.0; // hours in 1 day

    float years = floor(hours / data1);
    float remaining_hours = fmodf(hours, data1);
    
    float months = floor(remaining_hours / data2);
    float days = floor(fmodf(remaining_hours, data2) / 24.0);
    
    if(months >= data3)
    {
        years += floor(months / data3);
        months = fmodf(months, data3);
    }

    if((int)years < 1.0 && (int)months < 1.0 && (int)days < 1.0) // Только часы
    {
		heart;
        if((int)hours < 2.0)
            printf("%d hour left.", (int)hours); // 1 час
        else
            printf("%d hours left.", (int)hours); // Часы
		
		printf("\n");
    }
    else if((int)months < 1.0 && (int)days < 1.0 && (int)years >= 1.0) // Только года
    {
		heart;
        if((int)years < 2.0)
            printf("%d year left.", (int)years); // 1 год
        else
            printf("%d years left.", (int)years); // Года
		
		printf("\n");
    }
    else if((int)years < 1.0 && (int)months < 1.0 && (int)days >= 1.0) // Только дни
    {
		heart;
        if((int)days < 2.0) // День
            printf("%d day left.", (int)days); // Дней
        else
            printf("%d days left.", (int)days); // Дней
		
		printf("\n");
    }
    else if((int)years < 1.0 && (int)days < 1.0 && (int)months >= 1.0) // Только месяца
    {
		heart;
        if((int)months < 2.0)
            printf("%d month left.", (int)months); // 1 месяц
        else
            printf("%d months left.", (int)months); // Месяцев

		printf("\n");
    }
    else if((int)months < 1.0 && (int)years >= 1.0 && (int)days >= 1.0) // Только года и дни
    {
		heart;
        if((int)years > 1.0 && (int)days > 1.0) // Года и дни
            printf("%d years, %d days left.", (int)years, (int)days);
        else if((int)years > 1.0 && (int)days < 2.0) // Года и 1 день
            printf("%d years, %d day left.", (int)years, (int)days);
        else if((int)years < 2.0 && (int)days > 1.0) // 1 год и дней
            printf("%d year, %d days left.", (int)years, (int)days);
        else if((int)years < 2.0 && (int)days < 2.0) // 1 год и 1 день
            printf("%d year, %d day left.", (int)years, (int)days);

		printf("\n");
    }
    else if((int)days < 1.0 && (int)years >= 1.0 && (int)months >= 1.0) // Только года с месяцами
    {
		heart;
        if((int)years < 2.0 && (int)months < 2.0) // 1 год и 1 месяц
            printf("%d year, %d month left.", (int)years, (int)months);
        else if((int)years < 2.0 && (int)months > 1.0) // 1 год и месяцев
            printf("%d year, %d months left.", (int)years, (int)months);
        else if((int)months < 2.0 && (int)years > 1.0) // Года и 1 месяц
            printf("%d years, %d month left.", (int)years, (int)months);
		else
            printf("%d years, %d months left.", (int)years, (int)months); // Года и месяца

		printf("\n");
	}
    else if((int)years < 1.0 && (int)months >= 1.0 && (int)days >= 1.0) // Только месяца и дни
    {
		heart;
        if((int)months > 1.0 && (int)days > 1.0) // Месяцев и дней
            printf("%d months, %d days left.", (int)months, (int)days);
        else if((int)months < 2.0 && (int)days > 1.0) // 1 месяц и дней
            printf("%d month, %d days left.", (int)months, (int)days);
        else if((int)months > 1.0 && (int)days < 2.0) // Месяцев и 1 день
            printf("%d months, %d day left.", (int)months, (int)days);
        else if((int)months < 2.0 && (int)days < 2.0) // 1 месяц и 1 день
            printf("%d month, %d day left.", (int)months, (int)days);
			
		printf("\n");
    }
    else if((int)years >= 1.0 && (int)months >= 1.0 && (int)days >= 1.0) // Года с месяцами и с днями
    {
		heart;
        if((int)years > 1.0 && (int)months > 1.0 && (int)days > 1.0) // Года с месяцами и с днями
            printf("%d years, %d months, %d days left.", (int)years, (int)months, (int)days);
		else if((int)years > 1.0 && (int)months > 1.0 && (int)days < 2.0) // Года с месяцами и с 1 днем
			printf("%d years, %d months, %d day left.", (int)years, (int)months, (int)days);
		else if((int)years > 1.0 && (int)months < 2.0 && (int)days < 2.0) // Года с 1 месяцем и с 1 днем
			printf("%d years, %d month, %d day left.", (int)years, (int)months, (int)days);
	    else if((int)years > 1.0 && (int)months < 2.0 && (int)days > 1.0) // Года с 1 месяцем и с днями
			printf("%d years, %d month, %d days left.", (int)years, (int)months, (int)days);
		else if((int)years < 2.0 && (int)months < 2.0 && (int)days < 2.0) // 1 год с 1 месяцем и с 1 днем
			printf("%d year, %d month, %d day left.", (int)years, (int)months, (int)days);
	    else if((int)years < 2.0 && (int)months > 1.0 && (int)days > 1.0) // 1 год с месяцами с днями
			printf("%d year, %d months, %d days left.", (int)years, (int)months, (int)days);
		else if((int)years < 2.0 && (int)months < 2.0 && (int)days > 1.0) // 1 год с 1 месяцем и с днями
			printf("%d year, %d month, %d days left.", (int)years, (int)months, (int)days);
	    else if((int)years < 2.0 && (int)months > 1.0 && (int)days < 2.0) // 1 год с месяцами с 1 днем
			printf("%d year, %d months, %d day left.", (int)years, (int)months, (int)days);

		printf("\n");
	}
}
