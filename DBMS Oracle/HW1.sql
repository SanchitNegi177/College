-- Table 1 doctor
create table doctor(doc_id number primary key, name varchar2(20), phone_number number, department varchar2(20), specialization varchar2(20));

insert all
into doctor values (1, 'B.K Sharma', 6398884026, 'Neurology', 'Neural Surgeon')
into doctor values (2, 'S.K Patel', 9392384026, 'Anesthesiology', 'anesthesiologists')
into doctor values (3, 'K.K Rawat', 8798484326, 'Dermatology', 'Dermatopathology')
select * from dual;

insert into doctor values (1, 'B.K Sharma', 6398884026, 'Neurology', 'Neural Surgeon');
-- Table 2 patient
create table patient(name varchar2(20), patient_id number primary key, Phno_Number number, Doc_assigned number, foreign key (Doc_assigned) references doctor(doc_id));


insert all
into patient values('Aarav Sharma', 1123, 9876543210, 1)
into patient values('Isha Patel', 1242, 9987654321, 2)
into patient values('Rohan Mehta', 2013, 9123456789, 3)
select * from dual;

-- Table 3 medicine

create table medicine(name varchar2(20), medicine_id number primary key, cures varchar2(20), patient_id number, foreign key (patient_id) references patient(patient_id));

insert all
into medicine values('Cardiostatin', 101, 'heart failure', 1123)
into medicine values('Dermalix', 102, 'psoriasis', 2013)
select * from dual;


-- alter table medicine add primary key (medicine_id);

-- Table 4 bill

create table bill(patient_id number, serial_no number primary key, Total number, medicine_id number, foreign key (patient_id) references patient(patient_id), foreign key(medicine_id) references medicine(medicine_id));

-- alter table bill add constraint constrain_name foreign key (medicine_id) references medicine(medicine_id);


insert all
into bill values(1123, 20245678, 10000, 101)
into bill values(1242, 20241234, 23000, 101)
into bill values(2013, 20248765, 22000, 102)
select * from dual;

-- Table 5 Ward

create table ward(Ward_Number number primary key, patient_id number, doc_id number, foreign key(patient_id) references patient(patient_id), foreign key(doc_id) references doctor(doc_id));

-- alter table ward add constraint constrain_name foreign key (patient_id) references patient(patient_id);
-- alter table ward add constraint constrain_name foreign key (doc_id) references doctor(doc_id);


insert into ward values(1,1123,3)
insert into ward values(2,2013,1)
insert into ward values(3,1242,2)


insert all
into ward values(1,1123,3)
into ward values(2,2013,1)
into ward values(3,1242,2)
select * from dual