%erwthma 1
select tmima.IDtmimatos 
from tmima inner join Didaskalies on Didaskalies.IDtmimatos=Tmima.IDtmimatos inner join Kathigitis on
Kathigitis.IDkathigiti=Didaskalies.IDkathigiti inner join Mathima on Mathima.IDmathimatos = Didaskalies.IDmathimatos
where ((Mathima.titlos = 'Arxaia') AND (Kathigitis.epitheto = 'Antwniou'))


%erwthma 2
create view apousies1 as(
select Tmima.IDtmimatos , count(*) as 'A'
from Tmima inner join Mathitis on Mathitis.IDtmimatos=Tmima.IDtmimatos
group by Tmima.IDtmimatos)

select *
from apousies1

select IDtmimatos
from apousies1
where A = ( select max(A)
            from apousies1)



%erwthma 4
create view vathmoi as(
select vathmos.timi
from Mathitis inner join Vathmos on Mathitis.IDmathiti=Vathmos.IDmathiti
where Mathitis.imerominia_gennisis < '1991-01-01')


select *
from vathmoi

select AVG(timi) as 'mesos oros'
from vathmoi


%erwthma 3
select Kathigitis.onoma , Kathigitis.epitheto , count(Tmima.plithos_mathitwn) as 'plithos mathitwn'
from Tmima inner join Didaskalies on Tmima.IDtmimatos=Didaskalies.IDtmimatos inner join
Kathigitis on Didaskalies.IDkathigiti=Kathigitis.IDkathigiti 
where Kathigitis.onoma like 'G%'
group by Kathigitis.onoma , Kathigitis.epitheto



create view didaksi1 as(
select Kathigitis.onoma , Kathigitis.epitheto ,Tmima.IDtmimatos, Kathigitis.IDkathigiti
from Kathigitis inner join Didaskalies on Didaskalies.IDkathigiti = Kathigitis.IDkathigiti inner join
Tmima on Tmima.IDtmimatos = Didaskalies.IDtmimatos
where Kathigitis.onoma like 'G%')

select *
from didaksi1

select Kathigitis.onoma , Kathigitis.epitheto , COUNT(Tmima.plithos_mathitwn)
from didaksi1 inner join Tmima on Tmima.IDtmimatos = didaksi1.IDtmimatos inner join 
Kathigitis on didaksi1.IDkathigiti=Kathigitis.IDkathigiti
group by Kathigitis.onoma , Kathigitis.epitheto