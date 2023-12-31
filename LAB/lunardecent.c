#include <stdio.h>

float Velocity(float velocity, int throttle)
{
    float newVelocity;
    newVelocity = velocity + (0.1 * throttle - 1.5);
    return newVelocity;
}

float Height(float velocity, float height, int throttle)
{
    float newHeight;
    newHeight = height + velocity + ((0.1 * throttle - 1.5) / 2);
    return newHeight;
}

int main()
{
    float height = 250.0f;
    float velocity = -25.0f;
    int throttle = 0;
    int time = 0;

    printf("Lunar decent challenge!\n");
    printf("You will pilot a lunar decent the last 250m.\n");
    printf("Each turn represent 1-second decent time.\n");
    printf("Set the throttle for each turn (0-100)\n");
    printf("Time Height Velocity Throttle?\n");

    while (height > 0)
    {
        printf("%2d   %5.1f  %5.1f    ", time, height, velocity);
        scanf("%d", &throttle);

        if (throttle < 0 || throttle > 100)
        {
            printf("Throttle must be between 0 and 100.\n");
            continue;
        }

        height = Height(velocity, height, throttle);
        velocity = Velocity(velocity, throttle);
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