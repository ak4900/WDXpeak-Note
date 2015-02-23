drop table if exists entires;

create table entries(
    id integer primary key autoincrement,
    title string not null,
    text string not null
);
