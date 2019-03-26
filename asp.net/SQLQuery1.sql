insert into StudentDetails values('10','keerthana','9550503274','keerthana@gmail.com','1-85');
select * from StudentDetails;

create procedure insertDetails 
@id varchar(12),
@Name varchar(20),
@Phone varchar(13),
@Email varchar(25),
@Addr varchar(50)
as
insert into StudentDetails values(@id,@Name,@Phone,@Email,@Addr);
exec insertDetails '32','santhoshi', '7894565', 'dvxdhydf@hgdjg','1-86';
 
 create procedure deleteDetails
 @id varchar(12)
 as
 delete from StudentDetails where StudentId=@id;
 exec deleteDetails '1005';

 create procedure updateDetail
 @id varchar(12),
 @Name varchar(20),
@Phone varchar(13),
@Email varchar(25),
@Addr varchar(50)
 as
 update studentDetails set StudentName='@Name',PhoneNumber='@Phone',emailId='@Email',addr='@Addr' where StudentId='@id';

 exec updateDetail '32','Keerthana','9550','hgsdfg@cf','3-4-62/d';

 create procedure viewDetails
 as
 select * from StudentDetails;
 exec viewDetails;