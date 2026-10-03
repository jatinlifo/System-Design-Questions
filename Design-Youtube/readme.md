## System Design of Youtube
In this system design interview, we need to design a platform like YouTube that allows users to upload, stream, search, and share videos. Since YouTube serves billions of users worldwide, the system must be highly scalable, fault tolerant, and capable of delivering high-quality video streams with minimal latency.

We will design the complete YouTube system step by step, including its architecture, database design, APIs, scalability techniques, and low-level design.

Design a scalable video streaming platform capable of handling millions of concurrent users.
Understand how video uploads, transcoding, streaming, recommendations, and CDN-based content delivery work at scale.


## 1. Problem Statement
We need to design a YouTube-like video streaming platform that allows users to upload videos, watch videos, search for content, and interact with creators. Since millions of users may upload and stream videos simultaneously, the system must remain highly scalable, fault tolerant, and capable of delivering videos with minimal latency.

Users should be able to upload videos, stream videos, search for content, subscribe to channels, and interact through likes, comments, and shares.
The system should support adaptive video streaming, video processing, recommendations, and global content delivery.
The design should focus on scalability, efficient storage, fast video delivery, fault tolerance, and overall system performance.

## 2. Requirements
Before designing the system, we need to identify its functional and non-functional requirements. These requirements define the expected features and quality attributes of the YouTube platform.

## Funcational Requirements
"Functional requirements describe the core features that the system must suppot."

1. User should be able to register, login, logout authenticate securely.
2. User should be able to watch video, short, streaming.
3. User should be able to share video.
4. User should be able to do comments.
5. User should be able to save video, short.
6. User should be able to do subscribe, unsubscribe.
7. User should be able to like, dislike.
8. User should be able to report.
9. User should be able to create playlist and save watch later.
10. User (Creator) should be able to analyis own channel.
11. Usser (Creator) should be able to upload the video, streaming.


## Non-Functional Requirements.
"Non-Functional requirements define how well the system should peform under different conditions."

1. Availability: The platform should remain available with minimal downtime.
2. Scalability: It should support millions of concurrent users, video uploads, and streaming requests.
3. Reliability: Videos and user data should be stored safely without data loss.
4. Low Latency: Videos should start playing quickly with minimal buffering.
5. Performance: The system should provide fast search results and smooth video playback.
6. Security: User authentication, authorization, and data transmission should be secure.


## 3. Capacity Estimation
Before designing the architecure we need to estimate the expected traffic, storage, bandwith, and infrastructure requirements. These estimations help us choose the right database, storage systems, CDNs, and scaling strategy.

```
## Assumptions

Parameter	              Assumption
Registered Users	      3 Billion
Daily Active Users	      500 Million
Videos Uploaded per Day	  5 Million
Videos Watched per Day	  1 Billion
Average Video Size	      500 MB
Average Video Length	  10 Minutes
Read : Write Ratio	      200 : 1

## 3.1 Storage Estimation
Assume 5 million videos are uploaded every day and the average video size is 500 MB.

Daily Storage = 5 million * 500MB.
Daily Storage = 5 * 10^6 * 500 mb
Daily Storage = 25 * 10^8 mb
Daily Storage = 2500000000 mb
Daily Storage = 2.5 peta bit per day
Daily Storage = 2.5 PB per day

For 30 Days
Monthly Storage = 30 x 2.5 PB
Monthly Storage = 75 PB per month

## 3.2 Bandwidth Estimation
Assume users watch 1 billion videos per day and the average stremed video size is 500 MB.

Daily Streaming Data = 1 Billion * 500 MB
Daily Streaming Data = 500 PB/day

Daily Streaming Data per/sec = 500 PB / 86400
DSPS = 46 Tb/s

Estimated Bandwidth: ~46 Tb/s

3.3 ## Server Estimation
Assume one streaming server can hanlde 5 million concurrentt streaming sessions.

Number of Servers = 500 Million / 5 Million
Number of Server = 100 Servers

## 3.4 Requests Per Second (RPS) Estimation
Assume youtube process 1 billion video play requests per day.

RPS = 1 billion / 86400
RPS = 11574 requests/second
RPS = 11.5K RPS
```

## Estimated Traffic
The platform should be capable of handling approximately 11.5k requests per second, while supporting significantly higher traffic during peak hours.

-- Note: Thesse are average estimations, During viral events or peak hours, the actual traffic an be several times higher, so the system should be designed to handle traffic spikes efficiently.