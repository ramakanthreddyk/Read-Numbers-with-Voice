#include <stdio.h>
#include <windows.h>
#include <mmsystem.h>

void toWord ( int );
void toText ( int );
void checkIf ( int, int );
int getNumber ( int );


enum NUMBERS { ZERO, ONE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, ELEVEN, TWELVE,
                THIRTEEN, FOURTEEN, FIFTEEN, SIXTEEN, SEVENTEEN, EIGHTEEN, NINETEEN, TWENTY,
                THIRTY = 30, FORTY = 40, FIFTY = 50, SIXTY = 60, SEVENTY = 70, EIGHTY = 80,
                NINETY = 90, HUNDRED = 100, THOUSAND = 1000, LAKH =100000, CRORE = 10000000,
                TENS = -1 };

int main()
{
    int givenNumber;

    givenNumber = getNumber ( 999999999 );

    printf ( "\n%d\n", givenNumber );

    toText ( givenNumber );

    return 0;
}

void toWord ( int n )
{
    switch ( n )
    {
        case ZERO:
            printf ( "ZERO " ); PlaySound(TEXT("audio-numbers\\0.wav"), NULL, SND_SYNC);
            break;
        case ONE:
            printf ( "ONE " );PlaySound(TEXT("audio-numbers\\1.wav"), NULL, SND_SYNC);
            break;
        case TWO:
            printf ( "TWO " );PlaySound(TEXT("audio-numbers\\2.wav"), NULL, SND_SYNC);
            break;
        case THREE:
            printf ( "THREE " );PlaySound(TEXT("audio-numbers\\3.wav"), NULL, SND_SYNC);
            break;
        case FOUR:
            printf ( "FOUR " );PlaySound(TEXT("audio-numbers\\4.wav"), NULL, SND_SYNC);
            break;
        case FIVE:
            printf ( "FIVE " );PlaySound(TEXT("audio-numbers\\5.wav"), NULL, SND_SYNC);
            break;
        case SIX:
            printf ( "SIX " );PlaySound(TEXT("audio-numbers\\6.wav"), NULL, SND_SYNC);
            break;
        case SEVEN:
            printf ( "SEVEN " );PlaySound(TEXT("audio-numbers\\7.wav"), NULL, SND_SYNC);
            break;
        case EIGHT:
            printf ( "EIGHT " );PlaySound(TEXT("audio-numbers\\8.wav"), NULL, SND_SYNC);
            break;
        case NINE:
            printf ( "NINE " );PlaySound(TEXT("audio-numbers\\9.wav"), NULL, SND_SYNC);
            break;
        case TEN:
            printf ( "TEN " );PlaySound(TEXT("audio-numbers\\10.wav"), NULL, SND_SYNC);
            break;
        case ELEVEN:
            printf ( "ELEVEN " );PlaySound(TEXT("audio-numbers\\11.wav"), NULL, SND_SYNC);
            break;
        case TWELVE:
            printf ( "TWELVE " );PlaySound(TEXT("audio-numbers\\12.wav"), NULL, SND_SYNC);
            break;
        case THIRTEEN:
            printf ( "THIRTEEN " );PlaySound(TEXT("audio-numbers\\13.wav"), NULL, SND_SYNC);
            break;
        case FOURTEEN:
            printf ( "FOURTEEN " );PlaySound(TEXT("audio-numbers\\14.wav"), NULL, SND_SYNC);
            break;
        case FIFTEEN:
            printf ( "FIFTEEN " );PlaySound(TEXT("audio-numbers\\15.wav"), NULL, SND_SYNC);
            break;
        case SIXTEEN:
            printf ( "SIXTEEN " );PlaySound(TEXT("audio-numbers\\16.wav"), NULL, SND_SYNC);
            break;
        case SEVENTEEN:
            printf ( "SEVENTEEN " );PlaySound(TEXT("audio-numbers\\17.wav"), NULL, SND_SYNC);
            break;
        case EIGHTEEN:
            printf ( "EIGHTEEN " ); PlaySound(TEXT("audio-numbers\\18.wav"), NULL, SND_SYNC);
            break;
        case NINETEEN:
            printf ( "NINETEEN " );PlaySound(TEXT("audio-numbers\\19.wav"), NULL, SND_SYNC);
            break;

        case TWENTY:
            printf ( "TWENTY " );PlaySound(TEXT("audio-numbers\\20.wav"), NULL, SND_SYNC);
            break;
        case THIRTY:
            printf ( "THIRTY " );PlaySound(TEXT("audio-numbers\\30.wav"), NULL, SND_SYNC);
            break;
        case FORTY:
            printf ( "FORTY " );PlaySound(TEXT("audio-numbers\\40.wav"), NULL, SND_SYNC);
            break;
        case FIFTY:
            printf ( "FIFTY " );PlaySound(TEXT("audio-numbers\\50.wav"), NULL, SND_SYNC);
            break;
        case SIXTY:
            printf ( "SIXTY " );PlaySound(TEXT("audio-numbers\\60.wav"), NULL, SND_SYNC);
            break;
        case SEVENTY:
            printf ( "SEVENTY " );PlaySound(TEXT("audio-numbers\\70.wav"), NULL, SND_SYNC);
            break;
        case EIGHTY:
            printf ( "EIGHTY " );PlaySound(TEXT("audio-numbers\\80.wav"), NULL, SND_SYNC);
            break;
        case NINETY:
            printf ( "NINETY " );PlaySound(TEXT("audio-numbers\\90.wav"), NULL, SND_SYNC);
            break;
        case HUNDRED:
            printf ( "HUNDRED " );PlaySound(TEXT("audio-numbers\\hundred.wav"), NULL, SND_SYNC);
            break;
        case THOUSAND:
            printf ( "THOUSAND " );PlaySound(TEXT("audio-numbers\\thousand.wav"), NULL, SND_SYNC);
            break;
        case LAKH:
            printf ( "LAKH " );PlaySound(TEXT("audio-numbers\\lakh.wav"), NULL, SND_SYNC);
            break;
        case CRORE:
            printf ( "CRORE " );PlaySound(TEXT("audio-numbers\\crore.wav"), NULL, SND_SYNC);
            break;
    }
}

int getNumber ( int limit )
{
    int givenNumber;

    while ( TRUE )
    {
        printf ( "Please enter a number between 0 - %d only : ", limit );
        fflush ( stdin );
        scanf ( "%d", &givenNumber );
        if ( givenNumber >= 0 && givenNumber <= limit )
        {
            break;
        }
    }
    return givenNumber;
}

void toText ( int n )
{
    checkIf ( n, CRORE );
    n = n % CRORE;
    checkIf ( n, LAKH );
    n = n % LAKH;
    checkIf ( n, THOUSAND );
    n = n % THOUSAND;
    checkIf ( n, HUNDRED );
    n = n % HUNDRED;
    checkIf ( n, TENS );
}

void checkIf ( int n, int limit )
{
    int temp;

    if ( n >= limit )
    {
        temp = abs ( n / limit );
        if ( temp <= 20 )
        {
            toWord ( temp );
        }
        else
        {
            toWord ( temp / 10 * 10 );
            if ( ( temp % 10 ) > 0 )
            {

                toWord ( temp % 10 );
            }
        }
        toWord ( limit );
    }
}
