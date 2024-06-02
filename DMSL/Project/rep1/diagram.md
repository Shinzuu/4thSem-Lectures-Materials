                             +--------------+
                             |   Admin      |
                             |--------------|
                             |  AdminID (PK)|
                             |  Name        |
                             |  Email       |
                             |  Password    |
                             +--------------+
                                    |
                                    | 1
                                    |
                                    | M
                                  /  \
+------------+                    +--------------+                    +--------------+
|   Donor    |                    | Blood Unit   |                    |  Recipient   |
|------------|                    |--------------|                    |--------------|
| DonorID (PK)|------------------>|  UnitID (PK) |<-------------------| RecipientID (PK)|
|  Name      |                    |  BloodType   |                    |  Name        |
|  Age       |                    |  DonationDate|                    |  BloodType   |
|  BloodType |                    |  ExpiryDate  |                    |  Email       |
|  Email     |                    |  Status      |                    |  Phone       |
|  Phone     |                    |  DonorID (FK)|                    |  Address     |
|  Address   |                    |  ManagerID(FK)|                    +--------------+
|  AdminID (FK)                   +--------------+
+------------+                         | 1
       \ 1                              |
        \                               |
         M                              | M
         /                              |
        /                               |
+-------------+                    +--------------------+
|  Donation   |                    | Inventory Manager  |
|-------------|                    |--------------------|
| DonorID (FK)|                    | ManagerID (PK)     |
| UnitID (FK) |                    | Name               |
+-------------+                    | Email              |
                                    | Phone              |
                                    +--------------------+
                                                  /   \
                                                 1     M
                                                /       \
                                               /         \
+--------------+                    +--------------------+                    +------------------+
|  Test        |                    | Hospital/Clinic Rep|                    | Lab Technician   |
|--------------|                    |--------------------|                    |------------------|
| TechnicianID(FK)|---------------1 | RepID (PK)         |                    | TechnicianID (PK)|
| UnitID (FK) |<---------------M   | HospitalName       |                    | Name             |
+--------------+                    | Email              |                    | Email            |
                                    | Phone              |                    | Phone            |
                                    | Address            |                    +------------------+
                                    +--------------------+
                                           | 1
                                           |
                                           |
                                           | M
                                           |
                                           |
                                     +----------------------+
                                     | RepresentativeRequest|
                                     |----------------------|
                                     | RepID (FK)           |
                                     | UnitID (FK)          |
                                     +----------------------+
