#include <stdio.h>

float height = 250.0f;
float velocity = -25.0f;
int throttle = 0.0f;

float Velocity(float velocity)
    {
        
        float newVelocity;

        newVelocity = velocity + (0.1 * throttle - 1.5);

        return newVelocity;

    }
    
    float Height(float height, float velocity)
    {

        float newHeight;

        newHeight = height + velocity + ((0.1 * throttle - 1.5) / 2);

        return newHeight;

    }

int main()
{

    int time = 0;

    printf("Lunar decent challenge!\n");
    printf("You will pilot a lunar decent the last 250m.\n");
    printf("Each turn represent 1-second decent time.\n");
    printf("Set the throttle for each turn (0-100)\n");
    printf("Time Height Velocity Throttle?\n");

    while (height > 0)
    {
        printf(" %d   %.1f   %.1f   ", time, height, velocity);
        scanf("%d", &throttle);

        height = Height(height, velocity);
        velocity = Velocity(velocity);
        
        time++;

    }
    
    if (velocity < -2.0f)
    {

        printf("FAILED! Crash landing at %.1f m/s", velocity);

    } 
    else
    {

        printf("SUCCEEDED! Successful landing with a speed of %.1f m/s", velocity);

    }
    

    return 0;

}