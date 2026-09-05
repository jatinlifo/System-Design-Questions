
## Problem statement:
Parking garages play a crucial role in modern urban areas where the number of vehicles is rapidly increasing.
Managing limited parking space has become a major challenge for cities and businesses. Parking garages provide an 
efficient solution by optimizing space usage and reducing congestion.
They also offer convenient booking options through both online and offline methods.
Efficiently utilizes limited parking space in crowded areas
Reduces traffic congestion and improves vehicle management
Provides flexible booking options (online and offline)


## Now, my work
we have to make parking garages where parked any type of vechial.

## we need 
1. Parking garages how many floor
2. Entry car generate ticket and vechial type
3. Spot available 
4. if exit payment calculation
5. Exit 
6. Online support
7.Every time manage availibilty where spot is available because our system is online

## PARKING GARAGE
┌─────────────────────┐
│      Floor 3        │
│ [C][C][T][T][E][E]  │
├─────────────────────┤
│      Floor 2        │
│ [C][C][C][M][M][E]  │
├─────────────────────┤
│      Floor 1        │
│ [C][C][M][M][T][E]  │
└─────────────────────┘
            ↑
        Entrance
C = Car Spot.
M = Motorcycle Spot.
T = Truck Spot.
E = Electric Vehicle Spot.

## Functional Requirements
1. Vechial Entry our garage.
2. Check Vechial Type and spot available or not.
3. Generate Ticket and allocate spot.
4. Exit when user have to go.
5. Payment calculation.
6. Do Payment if online or offline.
7. After Exit update status system will online.
8. Every time Update Parking Availability

## Non-Functional Requirements
1. High Availabilty because our system is available 24 / 7
2. Low Latency -> parking allocation will fast
3. Scalability -> System should scalable becase 1 garage many floors and in future we would make another garages
5. Reliabilty  -> We are using online payment so system everytime should reliable
6. Concurrency -> System should not conflict carA book slot 101 that time carB book slot 101 we tackle this sitution. 

## Main Factor
1. User
2. Attendent
3. Admin

User -> enter -> generate ticket -> parking allocation -> payment -> exit
Attendent -> check vechial -> allow parking -> payment -> exit
Admin -> Add new features like gates, payment charges, floors like that

