-- Keep a log of any SQL queries you execute as you solve the mystery.

--了解报导相关情况 To learn reports
SELECT *
FROM crime_scene_reports r
WHERE
    r.year = 2021
    AND r.month = 7
    AND r.day = 28
    AND r.street = 'Humphrey Street'
    AND r.description LIKE '%thief%';
-- id 295   bakery    at 10:15am


--具体说了什么
SELECT *
FROM interviews i
WHERE
    i.year = 2021
    AND i.month = 7
    AND i.day = 28
    AND i.transcript LIKE '%thief%';


--了解店内情况 To learn the situation in bakery
SELECT *
FROM bakery_security_logs bsl
WHERE
    bsl.year = 2021
    AND bsl.month = 7
    AND bsl.day = 28
    AND bsl.hour = 10
    AND bsl.minute >= 15
    AND bsl.minute <= 25;
--5P2BI95, 94KL13X, 6P58WS2, 4328GD8, G412CB7, L93JTIZ, 322W7JE, 0NTHK55


--了解此人信息
SELECT *
FROM people p
WHERE
    p.license_plate
    IN ('5P2BI95', '94KL13X', '6P58WS2', '4328GD8', 'G412CB7', 'L93JTIZ', '322W7JE', '0NTHK55')
-- +--------+---------+----------------+-----------------+---------------+
-- |   id   |  name   |  phone_number  | passport_number | license_plate |
-- +--------+---------+----------------+-----------------+---------------+
-- | 221103 | Vanessa | (725) 555-4692 | 2963008352      | 5P2BI95       |
-- | 243696 | Barry   | (301) 555-4174 | 7526138472      | 6P58WS2       |
-- | 396669 | Iman    | (829) 555-5269 | 7049073643      | L93JTIZ       |
-- | 398010 | Sofia   | (130) 555-0289 | 1695452385      | G412CB7       |
-- | 467400 | Luca    | (389) 555-5198 | 8496433585      | 4328GD8       |
-- | 514354 | Diana   | (770) 555-1861 | 3592750733      | 322W7JE       |
-- | 560886 | Kelsey  | (499) 555-9472 | 8294398571      | 0NTHK55       |
-- | 686048 | Bruce   | (367) 555-5533 | 5773159633      | 94KL13X       |
-- +--------+---------+----------------+-----------------+---------------+

--取交集查看符合的人
INTERSECT

--查看符合时间段的取钱人信息
SELECT p.*
FROM
    atm_transactions at
    JOIN bank_accounts ba ON ba.account_number = at.account_number
    JOIN people p ON p.id = ba.person_id
WHERE
    at.year = 2021
    AND at.month = 7
    AND at.day = 28
    AND at.atm_location = 'Leggett Street'
    AND at.transaction_type = 'withdraw';
-- +-----+----------------+------+-------+-----+----------------+------------------+--------+---------+
-- | id  | account_number | year | month | day |  atm_location  | transaction_type | amount |  name   |
-- +-----+----------------+------+-------+-----+----------------+------------------+--------+---------+
-- | 267 | 49610011       | 2021 | 7     | 28  | Leggett Street | withdraw         | 50     | Bruce   |
-- | 336 | 26013199       | 2021 | 7     | 28  | Leggett Street | withdraw         | 35     | Diana   |
-- | 269 | 16153065       | 2021 | 7     | 28  | Leggett Street | withdraw         | 80     | Brooke  |
-- | 264 | 28296815       | 2021 | 7     | 28  | Leggett Street | withdraw         | 20     | Kenny   |
-- | 288 | 25506511       | 2021 | 7     | 28  | Leggett Street | withdraw         | 20     | Iman    |
-- | 246 | 28500762       | 2021 | 7     | 28  | Leggett Street | withdraw         | 48     | Luca    |
-- | 266 | 76054385       | 2021 | 7     | 28  | Leggett Street | withdraw         | 60     | Taylor  |
-- | 313 | 81061156       | 2021 | 7     | 28  | Leggett Street | withdraw         | 30     | Benista |
-- +-----+----------------+------+-------+-----+----------------+------------------+--------+---------+


------------------------既取了钱，又开车离开的人Bruce, Diana, Iman, Luca-----------------------------
-- +--------+-------+----------------+-----------------+---------------+
-- |   id   | name  |  phone_number  | passport_number | license_plate |
-- +--------+-------+----------------+-----------------+---------------+
-- | 396669 | Iman  | (829) 555-5269 | 7049073643      | L93JTIZ       |
-- | 467400 | Luca  | (389) 555-5198 | 8496433585      | 4328GD8       |
-- | 514354 | Diana | (770) 555-1861 | 3592750733      | 322W7JE       |
-- | 686048 | Bruce | (367) 555-5533 | 5773159633      | 94KL13X       |
-- +--------+-------+----------------+-----------------+---------------+


--查看符合条件的航班信息
SELECT a1.city, a2.city, f.year, f.month, f.day, f.hour, f.minute, pp.name
FROM
    flights f
    JOIN passengers p ON p.flight_id = f.id
    JOIN airports a1 ON a1.id = f.origin_airport_id
    JOIN airports a2 ON a2.id = f.destination_airport_id
    JOIN people pp ON pp.passport_number = p.passport_number
WHERE
    p.passport_number IN (7049073643, 8496433585, 3592750733, 5773159633)
    AND f.year = 2021
    AND f.month = 7
    AND f.day = 29;
--航班最早的只有8:20,罪犯应该是Bruce OR Luca


--看谁是主犯，查看通话记录
SELECT p1.name _caller, p2.name _receiver
FROM
    phone_calls pc
    JOIN people p1 ON p1.phone_number = pc.caller
    JOIN people p2 ON p2.phone_number = pc.receiver
WHERE
    pc.year = 2021
    AND pc.month = 7
    AND pc.day = 28
    AND pc.duration <= 60;
-- +---------+------------+
-- | caller  |  receiver  |
-- +---------+------------+
-- | Sofia   | Jack       |
-- | Kelsey  | Larry      |
-- | Bruce   | Robin      |
-- | Kathryn | Luca       |
-- | Kelsey  | Melissa    |
-- | Taylor  | James      |
-- | Diana   | Philip     |
-- | Carina  | Jacqueline |
-- | Kenny   | Doris      |
-- | Benista | Anna       |
-- +---------+------------+

--罪犯 Bruce, 从犯 Robin
