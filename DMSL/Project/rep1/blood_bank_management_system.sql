-- Admin Table
CREATE TABLE Admin (
    AdminID INT PRIMARY KEY,
    Name VARCHAR(100),
    Email VARCHAR(100),
    Password VARCHAR(100)
);

-- Donor Table
CREATE TABLE Donor (
    DonorID INT PRIMARY KEY,
    Name VARCHAR(100),
    Age INT,
    BloodType VARCHAR(10),
    Email VARCHAR(100),
    Phone VARCHAR(20),
    Address VARCHAR(255),
    AdminID INT,
    FOREIGN KEY (AdminID) REFERENCES Admin(AdminID)
);

-- Recipient Table
CREATE TABLE Recipient (
    RecipientID INT PRIMARY KEY,
    Name VARCHAR(100),
    BloodType VARCHAR(10),
    Email VARCHAR(100),
    Phone VARCHAR(20),
    Address VARCHAR(255)
);

-- Lab Technician Table
CREATE TABLE LabTechnician (
    TechnicianID INT PRIMARY KEY,
    Name VARCHAR(100),
    Email VARCHAR(100),
    Phone VARCHAR(20)
);

-- Inventory Manager Table
CREATE TABLE InventoryManager (
    ManagerID INT PRIMARY KEY,
    Name VARCHAR(100),
    Email VARCHAR(100),
    Phone VARCHAR(20)
);

-- Blood Unit Table
CREATE TABLE BloodUnit (
    UnitID INT PRIMARY KEY,
    BloodType VARCHAR(10),
    DonationDate DATE,
    ExpiryDate DATE,
    Status VARCHAR(50),
    DonorID INT,
    ManagerID INT,
    FOREIGN KEY (DonorID) REFERENCES Donor(DonorID),
    FOREIGN KEY (ManagerID) REFERENCES InventoryManager(ManagerID)
);

-- Hospital/Clinic Representative Table
CREATE TABLE HospitalClinicRepresentative (
    RepID INT PRIMARY KEY,
    HospitalName VARCHAR(100),
    Email VARCHAR(100),
    Phone VARCHAR(20),
    Address VARCHAR(255)
);

-- Donation Table (many-to-many relationship between Donor and Blood Unit)
CREATE TABLE Donation (
    DonorID INT,
    UnitID INT,
    PRIMARY KEY (DonorID, UnitID),
    FOREIGN KEY (DonorID) REFERENCES Donor(DonorID),
    FOREIGN KEY (UnitID) REFERENCES BloodUnit(UnitID)
);

-- Request Table (many-to-many relationship between Recipient and Blood Unit)
CREATE TABLE Request (
    RecipientID INT,
    UnitID INT,
    PRIMARY KEY (RecipientID, UnitID),
    FOREIGN KEY (RecipientID) REFERENCES Recipient(RecipientID),
    FOREIGN KEY (UnitID) REFERENCES BloodUnit(UnitID)
);

-- Test Table (many-to-many relationship between Lab Technician and Blood Unit)
CREATE TABLE Test (
    TechnicianID INT,
    UnitID INT,
    PRIMARY KEY (TechnicianID, UnitID),
    FOREIGN KEY (TechnicianID) REFERENCES LabTechnician(TechnicianID),
    FOREIGN KEY (UnitID) REFERENCES BloodUnit(UnitID)
);

-- Representative Request Table (many-to-many relationship between Hospital/Clinic Representative and Blood Unit)
CREATE TABLE RepresentativeRequest (
    RepID INT,
    UnitID INT,
    PRIMARY KEY (RepID, UnitID),
    FOREIGN KEY (RepID) REFERENCES HospitalClinicRepresentative(RepID),
    FOREIGN KEY (UnitID) REFERENCES BloodUnit(UnitID)
);
