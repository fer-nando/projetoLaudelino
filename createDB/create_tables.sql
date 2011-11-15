CREATE TABLE `mydb`.`Device` (
 `hostname` VARCHAR(20) NOT NULL ,
 `ip` VARCHAR(15) NULL ,
 `type` VARCHAR(15) NULL,
 `serie` VARCHAR(15) NULL,
 `up_time` INT NULL ,
 `rect_x` INT NULL,
 `rect_y` INT NULL,
 `rect_height` INT NULL,
 `rect_width` INT NULL,
 PRIMARY KEY (`hostname`) );

CREATE TABLE `mydb`.`Interface` (
 `id` INT NULL AUTO_INCREMENT,
 `type` VARCHAR(20) NULL ,
 `status` VARCHAR(4) NULL ,
 `name` VARCHAR(20) NULL ,
 `id_hostname` VARCHAR(20) NOT NULL ,
 PRIMARY KEY (`id`) ,
 FOREIGN KEY (`id_hostname` )
 REFERENCES `mydb`.`Device` (`hostname` ));

CREATE TABLE `mydb`.`HistBw` (
 `id` INT NULL AUTO_INCREMENT,
 `date` TIMESTAMP NULL ,
 `bw_in` INT NULL ,
 `bw_out` INT NULL ,
 `id_intf` INT NOT NULL ,
 PRIMARY KEY (`id`) ,
 FOREIGN KEY (`id_intf` )
 REFERENCES `mydb`.`Interface` (`id` ));

CREATE TABLE `mydb`.`Link` (
 `id` INT NULL AUTO_INCREMENT,
 `hostname_1` VARCHAR(20) NOT NULL ,
 `hostname_2` VARCHAR(20) NOT NULL ,
 `intf_1` INT NOT NULL ,
 `intf_2` INT NOT NULL ,
 PRIMARY KEY (`id`) ,
 FOREIGN KEY (`hostname_1` )
 REFERENCES `mydb`.`Device` (`hostname` ),
 FOREIGN KEY (`hostname_2` )
 REFERENCES `mydb`.`Device` (`hostname` ),
 FOREIGN KEY (`intf_1` )
 REFERENCES `mydb`.`Interface` (`id` ),
 FOREIGN KEY (`intf_2` )
 REFERENCES `mydb`.`Interface` (`id` ));
