CREATE TABLE p1_institution (id_institution INT auto_increment NOT NULL UNIQUE,
                                                                        name varchar(30) NOT NULL,
                                                                                         typeof enum('00','01'),
                                                                                                address varchar(100),
                                                                                                        phone varchar(15),
                                                                                                              rfc varchar(13),
                                                                                                                  PRIMARY key(id_institution));


CREATE TABLE p1_users
  (id_user INT auto_increment NOT NULL UNIQUE,
                                       name varchar(15) NOT NULL,
                                                        l_name varchar(20) NOT NULL,
                                                                           l_name2 varchar(20),
                                                                                   email varchar(40) NOT NULL,
                                                                                                     username varchar(10) NOT NULL UNIQUE,
                                                                                                                                   password varchar(10) NOT NULL,
                                                                                                                                                        phone varchar(15),
                                                                                                                                                              address varchar(100),
                                                                                                                                                                      rfc varchar(13),
                                                                                                                                                                          typeof enum('00','01','10'),
                                                                                                                                                                                 id_institution INT REFERENCES p1_institution(id_institution) ON DELETE CASCADE,
                                                                                                                                                                                                                                                        PRIMARY key(id_user));


CREATE TABLE p1_vehicle
  (record varchar(9) UNIQUE NOT NULL,
                            model varchar(15) NOT NULL,
                                              brand varchar(15) NOT NULL,
                                                                color varchar(15),
                                                                      id_user INT NOT NULL REFERENCES p1_users(id_user) ON DELETE CASCADE,
                                                                                                                                  PRIMARY key(record));


CREATE TABLE p1_state (id_state INT auto_increment NOT NULL UNIQUE,
                                                            name varchar(20) NOT NULL,
                                                                             PRIMARY key(id_state));


CREATE TABLE p1_sector
  (id_sector INT auto_increment NOT NULL UNIQUE,
                                         name varchar(20) NOT NULL,
                                                          id_state INT NOT NULL REFERENCES p1_state(id_state) ON DELETE CASCADE,
                                                                                                                        PRIMARY key(id_sector));


CREATE TABLE p1_parking
  (id_parking INT auto_increment NOT NULL UNIQUE,
                                          id_type int NOT NULL REFERENCES p1_type(id_type),
                                                                          address varchar(100),
                                                                                  longitude varchar(15),
                                                                                            latitude varchar(15),
                                                                                                     sizeof int NOT NULL,
                                                                                                                id_sector int NOT NULL REFERENCES p1_sector(id_sector) ON DELETE CASCADE,
                                                                                                                                                                                 id_institution int NOT NULL REFERENCES p1_institution(id_institution) ON DELETE CASCADE,
                                                                                                                                                                                                                                                                 rate decimal(5,2) NOT NULL,
                                                                                                                                                                                                                                                                                   PRIMARY key(id_parking));


CREATE TABLE p1_type (id_type int auto_increment NOT NULL UNIQUE,
                                                          typeof varchar(25) NOT NULL);


CREATE TABLE p1_park
  (id_park int auto_increment NOT NULL UNIQUE,
                                       entryof datetime DEFAULT CURRENT_TIMESTAMP NOT NULL,
                                                                                  exitof datetime DEFAULT NULL,
                                                                                                          record varchar(9) NOT NULL REFERENCES p1_vehicle(record) ON DELETE CASCADE,
                                                                                                                                                                             id_parking int NOT NULL REFERENCES p1_parking(id_parking) ON DELETE CASCADE,
                                                                                                                                                                                                                                                 PRIMARY key(id_park));


CREATE TABLE p1_schedule
  (DAY enum('mon','tue','wed','thu','fri','sat','sun') NOT NULL,
                                                       startof TIME NOT NULL,
                                                                    endof TIME NOT NULL,
                                                                               id_parking int NOT NULL REFERENCES p1_parking(id_parking) ON DELETE CASCADE,
                                                                                                                                                   PRIMARY key(id_parking, DAY));
