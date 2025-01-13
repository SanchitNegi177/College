
-- Granting permissions
create user Siddhartha identified by password;
grant connect,resource to Siddhartha;
--revoking permissions
revoke connect,resource from Siddhartha

--makeiong savepoint s1
savepoint s1;

create table doctor(doc_id number primary key, name varchar2(20), phone_number number, department varchar2(20), specialization varchar2(20));

insert all
into Doctor values(4, 'Sid1', 1134611111, 'eh', 'huh')
into Doctor values(5, 'Sid2', 1111123411, 'eh', 'huh')
into Doctor values(6, 'Sid3', 11234111111, 'eh', 'huh')
into Doctor values(7, 'Sid4', 11111111214, 'eh', 'huh')
select * from dual;

select * from Doctor;

-- Rolling back to s1
rollback to s1;


alter table doctor add unique(phone_number);
alter table doctor add constraint length CHECK(length(phone_number) = 10);
alter table doctor add CHECK(length(phone_number) = 10);
alter table doctor modify department NOT NULL;
alter table doctor modify specialization DEFAULT 'General';

--adding different constraint to table after creation
alter table temp add unique(uniq)
alter table temp def DEFAULT NULL;
alter table temp add check(chek);
alter table temp modify chek CHECK(length(chek) > 4);
alter table temp no_null NOT NULL;
alter table temp add primary key(primary_col)

----------------------------
-- temp(DEF, UNIQ, CHEK,NN)
alter table temp modify NN NOT NULL;           -- domain constraints
alter table temp modify DEF default 10000;


alter table doctor add contraint salary_check check(salary>1800);
alter table temp add constraint PK primary key(id); --entity constraints
alter table temp add constraint UQ unique(uniq)

create table patient(name varchar2(20), patient_id number primary key, Phno_Number number, 
Doc_assigned number, foreign key (Doc_assigned) references doctor(doc_id) on delete cascade);
----------------------------


-- removing constraint
alter table temp drop primary key;

--Displaying constraints
select constraint_name, column_name from user_constraints where table_name = 'DOCTOR';


SELECT constraint_name, constraint_type
FROM user_constraints
WHERE table_name = 'DOCTOR';



--Renaming constraintss
alter table temp rename constraint SYS_C007021 to default_constraint;
alter table temp rename constraint  SYS_C007024 to no_null_allowed;

--Renaming column
ALTER TABLE table_name RENAME COLUMN old_column_name TO new_column_name;


--trying to insert null into constraint no null allowed
insert into temp values('Yeah this is value', 1, 'False', NULL);

insert into temp(DEF, UNIQ, CHEK) values('Yeah this is value', 1, 'False');
--Says cannot insert NULL into ("SID"."TEMP"."NO_NULL")


insert all
into temp values('ABCD', 1, 'False', 1, 20)
into temp values('ABCD', 2, 'False', 1, 20)
into temp values('ABCD', 3, 'False', 1, 20)
into temp values('ABCD', 4, 'False', 1, 20)
into temp values('ABCD', 5, 'False', 1, 20)
selcet * from dual;

-- adding a column for primary key
alter table temp add primary_col number;
-- or to add primary key constraint
alter table temp add primary_col number primary_key;
-- adding primary key constraint
alter table temp add primary key(primary_col)


-- Says
-- ORA-02437: cannot validate (SID.SYS_C007028) - primary key violated

