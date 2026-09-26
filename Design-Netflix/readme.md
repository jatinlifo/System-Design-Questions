## Problem Statement 
Designing Netflix involves building a scalable and highly available video streaming platform that delivers movies and TV shows to millions of users worldwide. This article explains the complete system design of Netflix, covering its architecture, APIs, database design, scalability, and performance considerations.

Learn how Netflix handles video streaming, content delivery, user recommendations, and playback at massive scale.
Understand the high-level architecture, low-level design, database choices, APIs, caching strategies, CDN usage, and techniques used to build a reliable video streaming platform.


## Tackle Part
## 1. Problem Statement
We need to design a Netflix-like video streaming platform that enables millions of users to watch movies and TV shows on demand with high-quality playback. The system should be scalable, highly available, and capable of delivering video content with low latency across different regions.

Users should be able to browse content, stream videos, search titles, and receive personalized recommendations seamlessly.
The system should ensure smooth video playback with minimal buffering while supporting multiple devices and varying network conditions.
The design should focus on scalability, fault tolerance, content delivery, data storage, and overall system performance.

## Requriements.

## 1. Functional Requriemens.

1. User want to see UI
2. User should be able to register, login, logout securly.
3. User should be able to choose the plane
4. User should be able to see panel, like watch animes, watch marvels, watch etc.
5. User should be able to search.
6. User should be personalized content recommendations base their watch history.
7. User should be watch any content.
8. When user leave page and return again so watch continue track history.
9. User should be share your account another member.
10. User should be download content can watch offline.
11. User should be rating.

## 2. Non-functional Requirements.

1. Availability: System should be available with minimum down time.
2. Scalability: System should be scalable when come huge traffic.
3. Reliability: When any sever fail our system should be work smoothly.
4. Security : System should be secure like user detail , subscription plane, system data like movies.
5. Low Latency : Video start with minimal buffering time
6. Fault Tolerance: The system should be continue operating even  server or services fail.
7. Perfomance: System should be deliver hight quality video on different devices like mobile, laptop, pc.
8. Global Network Delivery: System should be deliver data word wide using content delivery networks. 

## Capacity Estimation. 

Before designing the architecture, we need to estimate the expected traffic, storage, and bandwidth requirements. These estimations help us choose the right CDN, storage, database, cache, and scaling strategy.

```

## Assumptions.
Parameter	            Assumption
Registered Users =	    300 Million
Daily Active Users =	100 Million
Daily Video Views =	    1 Billion
Average Video Size =	500 MB
Read : Write Ratio =	1000 : 1


## Storage Estimation
Assume around 100,000 new videos are uploaded every day, and the average video size is 500 MB.

Daily Storage = 100,000 × 500 MB
Daily Storage = 5 * 10^7 mb
Daily Storage = 50 TB/day

For 30 days, Monthly Storage

MS = 30 × 50 TB
Ms = 1.5 PB


## Estimated Storage: 1.5 PB/month (excluding replicas and backups).

Bandwidth Estimation
Assume the platform streams approximately 1 billion video views per day, with an average streamed size of 500 MB.

Daily Data Transfer = 1 Billion × 500 MB

Daiy Data Transfer = 500 PB/day

Bandwidth = 500 PB / 86,400 seconds

Bandwidth ≈ 46 Tb/s

Estimated Bandwidth: ~46 Tb/s


Note: Most of this bandwidth is handled through geographically distributed CDNs rather than the origin servers.

## Server Estimation
Assume a single streaming server can handle approximately 50,000 concurrent streaming sessions.

Number of Streaming Servers  = 100 Million / 50,000

Number of Streaming Servers = 2,000 Servers

Estimated Streaming Servers: 2,000 Servers (excluding CDN edge servers).

## Requests Per Second (RPS) Estimation
To estimate the traffic handled by the platform, we calculate the average number of streaming requests processed every second.

Assume Netflix serves 1 billion video play requests per day.

Requests Per Second (RPS) = 1 Billion / 86,400

RPS ≈ 11,574 requests/second

RPS ≈ 11.5K RPS

Estimated Traffic: The platform should be capable of handling approximately 11.5K requests per second, with the ability to support significantly higher traffic during peak viewing hours.

Note: This is an average estimation. During peak hours (evenings, weekends, or new content releases), the actual RPS can be several times higher, so the system should be designed to handle sudden traffic spikes efficiently.

```