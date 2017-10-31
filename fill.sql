-- Instituciones

INSERT INTO p1_institution(name,typeof,address,phone,rfc)
VALUES ('Gobierno Federal',
        '00',
        'Mexico, CDMX',
        '5514321789',
        NULL);


INSERT INTO p1_institution(name,typeof,address,phone,rfc)
VALUES ('El instituto',
        '01',
        'Mexico, CDMX',
        '5534129534',
        NULL);

-- Vehiculos

INSERT INTO p1_vehicle(record,model,brand,color,id_user)
VALUES('100-TUS',
       'Astra',
       'Chevrolet',
       'gris',
       3);


INSERT INTO p1_vehicle(record,model,brand,color,id_user)
VALUES('989-AKG',
       'Versa',
       'Nisan',
       'negro',
       3);


INSERT INTO p1_vehicle(record,model,brand,color,id_user)
VALUES('342-DFE',
       'Vento',
       'Volkswagen',
       'blanco',
       4);


INSERT INTO p1_vehicle(record,model,brand,color,id_user)
VALUES('1022-ad',
       'Chevy',
       'Chevrolet',
       'azul',
       5);

-- Usuarios

INSERT INTO p1_users(name,l_name,l_name2,email,username,password,phone,address,rfc,typeof,id_institution)
VALUES ('Ricardo',
        'De la Vega',
        'Barron',
        'rdelavega63@gmail.com',
        'rdb63ft0',
        'rdb36oan',
        '5524682346',
        'CDMX,Mexico',
        'VEBR270697SA0',
        '01',
        1);


INSERT INTO p1_users(name,l_name,l_name2,email,username,password,phone,address,rfc,typeof,id_institution)
VALUES ('Ricardo',
        'De la Vega',
        'Barron',
        'rdelavega63@gmail.com',
        'rdb64ft0',
        'rdb36oan',
        '5524682346',
        'CDMX,Mexico',
        'VEBR270697SA0',
        '00',
        NULL);


INSERT INTO p1_users(name,l_name,l_name2,email,username,password,phone,address,rfc,typeof,id_institution)
VALUES ('Michelle',
        'Allegretti',
        'Rodriguez',
        'm.allegretti@gmail.com',
        'mar95yth',
        'mar56eiz',
        '5552467250',
        'CDMX, Mexico',
        'ALMR111297FG4',
        '01',
        2);


INSERT INTO p1_users(name,l_name,l_name2,email,username,password,phone,address,rfc,typeof,id_institution)
VALUES ('Sandra',
        'Leon',
        'Laguna',
        'sasyanlly@gmail.com',
        'sll98ur7',
        'sll05ana',
        '5556405439',
        'CDMX, Mexico',
        'LESL050198FR9',
        '10',
        NULL);


INSERT INTO p1_users(name,l_name,l_name2,email,username,password,phone,address,rfc,typeof,id_institution)
VALUES ('Diana',
        'Gonzalez',
        'Torres',
        'dianitag23@gmail.com',
        'dgt48vfr',
        'dgt89azs',
        '5581153688',
        'CDMX,Mexico',
        'GODT211098SA0',
        '10',
        NULL);


INSERT INTO p1_users(name,l_name,l_name2,email,username,password,phone,address,rfc,typeof,id_institution)
VALUES ('Angel',
        'Rodriguez',
        'Mendoza',
        'angelrodmen8@gmail.com',
        'arm78ye',
        'arm88lza',
        '5547979437',
        'CDMX,Mexico',
        'ROMA020897GH8',
        '10',
        NULL);

-- Estados

INSERT INTO p1_state(name)
VALUES('CDMX');


INSERT INTO p1_state(name)
VALUES('Estado de Mexico');

-- Sector

INSERT INTO p1_sector(name,id_state)
VALUES('Condesa',
       1);


INSERT INTO p1_sector(name,id_state)
VALUES('Centro',
       1);


INSERT INTO p1_sector(name,id_state)
VALUES('Napoles',
       1);


INSERT INTO p1_sector(name,id_state)
VALUES('Santa Fe',
       1);


INSERT INTO p1_sector(name,id_state)
VALUES('Toluca',
       2);


INSERT INTO p1_sector(name,id_state)
VALUES('Tlalnepantla',
       2);


INSERT INTO p1_sector(name,id_state)
VALUES('Nezahualcoyotl',
       2);

-- Tipos

INSERT INTO p1_type(typeof)
VALUES('Estacionamiento Publico');


INSERT INTO p1_type(typeof)
VALUES('Parquimetro');

-- Parking

INSERT INTO p1_parking(id_type,address,longitude,latitude,sizeof,id_sector,id_institution,rate)
VALUES (2,
        'Condesa, CDMX',
        NULL,
        NULL,
        2,
        1,
        1,
        12.45);


INSERT INTO p1_parking(id_type,address,longitude,latitude,sizeof,id_sector,id_institution,rate)
VALUES (2,
        'Toluca 2, CDMX',
        NULL,
        NULL,
        2,
        5,
        1,
        13.45);


INSERT INTO p1_parking(id_type,address,longitude,latitude,sizeof,id_sector,id_institution,rate)
VALUES (2,
        'Av. Anzures, CDMX',
        NULL,
        NULL,
        2,
        3,
        1,
        14.45);


INSERT INTO p1_parking(id_type,address,longitude,latitude,sizeof,id_sector,id_institution,rate)
VALUES (1,
        'Av. Costales, CDMX',
        NULL,
        NULL,
        2,
        4,
        2,
        16.45);


INSERT INTO p1_parking(id_type,address,longitude,latitude,sizeof,id_sector,id_institution,rate)
VALUES (1,
        'Av. Limones, CDMX',
        NULL,
        NULL,
        7,
        2,
        2,
        17.45);


INSERT INTO p1_parking(id_type,address,longitude,latitude,sizeof,id_sector,id_institution,rate)
VALUES (2,
        'Av. Gutemberg, EMX',
        NULL,
        NULL,
        2,
        5,
        1,
        12.45);


INSERT INTO p1_parking(id_type,address,longitude,latitude,sizeof,id_sector,id_institution,rate)
VALUES (2,
        'Av. 22 de Febrero, EMX',
        NULL,
        NULL,
        2,
        6,
        1,
        16.45);


INSERT INTO p1_parking(id_type,address,longitude,latitude,sizeof,id_sector,id_institution,rate)
VALUES (1,
        'Av. Aguascalientes, EMX',
        NULL,
        NULL,
        2,
        7,
        2,
        19.45);


INSERT INTO p1_parking(id_type,address,longitude,latitude,sizeof,id_sector,id_institution,rate)
VALUES (2,
        'Condesa no. 2, CDMX',
        NULL,
        NULL,
        2,
        1,
        1,
        16.45);


INSERT INTO p1_parking(id_type,address,longitude,latitude,sizeof,id_sector,id_institution,rate)
VALUES (2,
        'Tlalnepantla no. 2, CDMX',
        NULL,
        NULL,
        2,
        6,
        1,
        18.45);


INSERT INTO p1_parking(id_type,address,longitude,latitude,sizeof,id_sector,id_institution,rate)
VALUES (2,
        'Tlalnepantla no. 3, CDMX',
        NULL,
        NULL,
        2,
        6,
        1,
        11.45);

-- Park

INSERT INTO p1_park(entryof,exitof,record,id_parking)
VALUES ('2017-10-13 11:36:08',
        NULL,
        '100-TUS',
        5);


INSERT INTO p1_park(entryof,exitof,record,id_parking)
VALUES ('2017-10-30 11:36:08',
        NULL,
        '100-TUS',
        9);


INSERT INTO p1_park(entryof,exitof,record,id_parking)
VALUES ('2017-08-30 11:36:08',
        NULL,
        '342-DFE',
        9);


INSERT INTO p1_park(entryof,exitof,record,id_parking)
VALUES ('2017-01-23 13:06:25',
        '2017-01-23 15:14:13',
        '342-DFE',
        1);


INSERT INTO p1_park(entryof,exitof,record,id_parking)
VALUES ('2017-02-01 19:25:39',
        '2017-02-01 22:43:00',
        '342-DFE',
        3);


INSERT INTO p1_park(entryof,exitof,record,id_parking)
VALUES ('2017-02-02 07:57:21',
        '2017-02-02 17:32:59',
        '342-DFE',
        3);


INSERT INTO p1_park(entryof,exitof,record,id_parking)
VALUES ('2017-02-02 20:57:21',
        '2017-02-02 22:32:59',
        '342-DFE',
        5);


INSERT INTO p1_park(entryof,exitof,record,id_parking)
VALUES ('2017-02-02 12:57:21',
        '2017-02-02 13:32:59',
        '342-DFE',
        5);


INSERT INTO p1_park(entryof,exitof,record,id_parking)
VALUES ('2017-02-02 20:57:21',
        '2017-02-10 13:32:59',
        '100-TUS',
        5);


INSERT INTO p1_park(entryof,exitof,record,id_parking)
VALUES ('2017-01-05 20:26:02',
        '2017-01-05 23:56:31',
        '1022-ad',
        2);


INSERT INTO p1_park(entryof,exitof,record,id_parking)
VALUES ('2017-06-08 20:42:30',
        '2017-06-09 01:51:10',
        '1022-ad',
        6);


INSERT INTO p1_park(entryof,exitof,record,id_parking)
VALUES ('2017-05-14 12:06:24',
        '2017-05-14 20:59:11',
        '1022-ad',
        5);


INSERT INTO p1_park(entryof,exitof,record,id_parking)
VALUES ('2017-06-27 16:58:03',
        '2017-06-27 23:02:23',
        '1022-ad',
        7);


INSERT INTO p1_park(entryof,exitof,record,id_parking)
VALUES ('2017-08-02 10:01:24',
        '2017-08-02 23:56:08',
        '1022-ad',
        4);


INSERT INTO p1_park(entryof,exitof,record,id_parking)
VALUES ('2017-12-11 22:37:56',
        NULL,
        '1022-ad',
        6);


INSERT INTO p1_park(entryof,exitof,record,id_parking)
VALUES ('2017-12-11 12:37:56',
        NULL,
        '1022-ad',
        5);


INSERT INTO p1_park(entryof,exitof,record,id_parking)
VALUES ('2017-12-11 20:37:56',
        NULL,
        '1022-ad',
        5);

-- Schedules

INSERT INTO p1_schedule
VALUES('tue',
       '12:00:00',
       '21:00:00',
       1);


INSERT INTO p1_schedule
VALUES('wed',
       '12:00:00',
       '21:00:00',
       1);


INSERT INTO p1_schedule
VALUES('sat',
       '12:00:00',
       '21:00:00',
       1);


INSERT INTO p1_schedule
VALUES('sun',
       '10:00:00',
       '21:00:00',
       1);


INSERT INTO p1_schedule
VALUES('thu',
       '20:00:00',
       '21:00:00',
       1);


INSERT INTO p1_schedule
VALUES('fri',
       '00:00:00',
       '21:00:00',
       1);


INSERT INTO p1_schedule
VALUES('mon',
       '18:00:00',
       '21:00:00',
       1);


INSERT INTO p1_schedule
VALUES('tue',
       '12:00:00',
       '21:00:00',
       9);


INSERT INTO p1_schedule
VALUES('mon',
       '14:00:00',
       '21:00:00',
       9);
