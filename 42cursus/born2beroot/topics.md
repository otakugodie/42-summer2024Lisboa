
## project overview

apt and aptitude are packet managers (advanced packaging tool)

Debian is user-friendlier compared to Rocky. It's more suitable for beginner users.

The Logical Volume Manager (LVM) provides tools to create virtual block devices from physical devices.

AppArmor and SELinux act as gatekeepers of the system. They control what apps can do or cannot do.
(AppArmor comes usually installed on Debian based distros)

## simple configuration

- assure there's no graphical interface
	- `systemctl status display-manager`
- check OS
	- `hostnamectl`
- check ufw
	- `sudo systemctl status ufw`
- check ssh
	- `sudo systemctl status ssh`

## user

- check groups from user
	- `groups`
- create user
	- `sudo adduser user123`
		- asks for password, and contact details
		- adds user123 to group "users"
	- ! `sudo useradd user_abc`
		- adds user_abc to groups, but user_abc does not belong to "users" group
		- it doesn't ask for a password
- create group
	- `sudo groupadd group`
	- `sudo addgroup group`
- associate user to a group
	- `sudo usermod -aG group user`
	- `sudo gpasswd -a user group`

## hostname and partitions

- verify hostname
	- `hostnamectl`
	- `hostnamectl status`
- change hostname
	- `sudo hostnamectl cmanuel- new_hostname`
	- edit `/etc/hostname`
- display partitions of VM
	- `lsblk`

The Logical Volume Manager (LVM) provides tools to create virtual block devices from physical devices.
Virtual devices may be easier to manage than physical devices, and can have capabilities beyond what the physical devices provide themselves.


## sudo

- verify sudo
	- `getent group sudo`
	- `systemctl status sudo`
- show how to assign a new user to sudo group
	- `usermod -aG sudo username`
	- `sudo visudo`
- purpose of **sudo**
	- sudo enables users to run program with the security privileges of another user, by default the superuser
- use of sudo
	- `sudo apt update`
- verify if sudo commands have been logged
	- `cat /var/log/sudo`


## ufw

- check ufw
	- `systemctl status ufw`
- brief summary on ufw
	- Uncomplicated Firewall is a interface to configure the firewall, by allowing and denying ports. (open and closing ports)
- list rules
	- `sudo ufw status`
- add a new rule
	- `sudo ufw enable 8080`
- delete rule
	- `sudo ufw status numbered`
	- `sudo ufw delete #number`

## ssh

- check ssh
	- `systemctl status ssh`
- brief summary on ssh
	- **ssh**, secure shell, provides tools to remotely access and manage computer systems and manage authentications keys. it uses 2 keys: public and private key
- check SSH only uses port 4242
	- edit `/etc/ssh/sshd_config`, search for `Port 4242`
- connect via ssh with a new username


## monitoring.sh

- explain script
	- `cat /home/cmanuel-/monitoring.sh`
- summary of cron
	- cron job is a tool to schedule commands or scripts to happen at specific times.
- edit cron job
	- `sudo crontab -u root -e`
- disable cron
	- `sudo systemctl disable cron`



----

# extra

## create user

- `sudo adduser user123`
	- asks for password, and contact details
	- adds user123 to group "users"

- ! `sudo useradd user_abc`
	- adds user_abc to groups, but user_abc does not belong to "users" group
	- it doesn't ask for a password

## remove user

- `sudo deluser user123`
- `sudo userdel user123`
## create group

- `sudo groupadd group`
- `sudo addgroup group`
## remove group

- `sudo groupdel group`
- `sudo delgroup group`
## add user to group

- `sudo usermod -aG group user`
- `sudo gpasswd -a user group`

## remove user from group

- `sudo usermod -rG group user`
- `sudo gpasswd -d user group`
## get info on commands

- `sudo usermod`
- `sudo gpasswd`
- `getent --help`

---

password common password

config
`/etc/pam.d/common-password`

all commented
`/etc/security/pwquality.conf`

---




# Ver particiones
lsblk

# Instalar un paquete
apt install package_name

# Reiniciar la maquina
sudo reboot

# Ver hostname o IP de hostname
hostname / hostname -I

# Apagar maquina
sudo systemctl poweroff

# Validar si sudo se instalo
sudo -V opcional: sudo -V | more

# Crear un usuario
sudo adduser cuenta_usuario
## Si es un usuario que ya existe aparecera un mensaje

# Crear un grupo
sudo addgroup nombre_grupo

## Para validar si ya se creo un grupo y/o ver los miembros del grupo
getent group nombre_grupo o podemos ver en cat /etc/group

# Añadir a un usuario en un grupo
sudo adduser cuenta_usuario nombre_grupo

# SSH - Validar que ssh o ufw están corriendo o reiniciarlo
sudo service ssh status ó sudo service ufw status ó sudo grep Port /etc/ssh/sshd_config
sudo service ssh restart -> sudo service nombre_servicio restart

# SSH - Para configurar ssh
vim /etc/ssh/sshd_config (Como root o sudo), seguido revisar
vim /etc/ssh/ssh_config

# SSH - Conectarse desde PC externo
ssh nombre_usuario@direccion_ip -p 4242

# UFW - Para habilitar UFW
sudo ufw enable

# UFW - Permitir conexiones por puerto
sudo ufw allow 4242 -> sudo ufw allow #### (### No de Puerto)

# UFW - Validar el status de los puertos de UFW
sudo ufw status

# SUDO - Password fuerte (Configurar contraseña)
Creo un fichero en /etc/sudoers.d/sudo_conf -> Lo llame sudo_conf -> touch /etc/sudoers.d/sudo_conf

# Politicas de contraseñas fuertes
En /etc/login.defs
	PASS_MAX_DAYS -> tiempo de expiración de la contraseña
	PASS_MIN_DAYS -> mínimo de días permitido antes de modificar una contraseña
	PASS_WARN_AGE -> mensaje de aviso días que faltan para que expire su contraseña
En vim /etc/pam.d/common-password
	minlen=10
	ucredit=-1 	-> 	Upper
	dcredit=-1	->	Digit
	lcredit=-1	->	Lower
	maxrepeat=3	-> +3 veces seguidas el mismo carácter
	reject_username -> No puede contener nombre_usuario
	difok=7		->	Al menos 7 caracteres que no sean parte de la antigua contraseña
	enforce_for_root	-> Esta politica aplica para el usuario root


# USER - Validar y ajustar expiracion de dias
sudo chage -l username
sudo chage -m <time> nombre_usuarios (time # de dias, ex. 5), m: minimo
sudo chage -M <time> <username>, M: Maximo de dias entre cambios

# Network - Validar si un puerto esta libre o no
ss -tuln | grep -E '4242' -> No deberia mostrar nada en pantalla, si el puerto esta libre
Si esta ocupado, lo cambio en virtualbox en Host port

# CRONNTAB - Configurar crontab
sudo crontab -u root -e
*/10 * * * * sh /ruta del script (*/10 * * * * sh /home/diegfern/monitoring.sh)

# CRON - Validar si cron esta ejecutandose
## Ver crons del usuario -> 
crontab -l

## Ver status del cron y habilitar
sudo systemctl status cron
sudo systemctl enable cron








Evaluation
Guias
https://github.com/gemartin99/Born2beroot-Tutorial?tab=readme-ov-file#7--signaturetxt-
https://github.com/pasqualerossi/Born2BeRoot-Guide

Evaluacion
https://www.42evals.com/
https://www.42evals.com/sheets/66b9c78fe6188711fc26b86a

Voy en Hostname and partitions
Eval Born2BeRoot

Validar firma digital:
Voy a la ruta donde tengo el .vdi de la maquina virtual y ejecuto en el terminal
  'shasum nombre_maquina_virtual.vdi'
  Espero a que muestre el resultados y comparo que sean iguales.

Clono la maquina virtual y la ejecuto

Desencripto la particion y accedo con la cuenta de usuario

Obtengo la IP de la maquina
  'hostname -I'

Valido que el ssh este funcionando
  'sudo service ssh status'

Con la IP me conecto desde un Terminal con
  'ssh nombre_usuario@direccion_ip_servidor -p 4242'
  Ingreso password

Setup:
  Para validar que no hay entorno grafico se puede ejecutar
    'systemctl status display-manager'
    No debe aparecer ningun servicio como resultado

  Validar que el Firewall UFW (Firewall Descomplicado) esta en uso
    'sudo service ufw status'

  Validar que el SSH esta en uso
    'sudo service ssh status'

  Validar el SO
    'uname -a' o 'hostnamectl'

  Validar que un usuario pertenece a un grupo
    'getent group nombre_grupo'
    El usuario debe estar en el listado


Usuario:
  Crear un nuevo usuario (se debe validar los elementos de seguridad de la contrasena)
  'sudo adduser nombre_usuario'

  En caso de desear eliminar un usuario
  'sudo userdel -r nombre_usuario' -> -r (--remove): elimina directorio personal y su contenido

  En caso de preguntas sobre la política de contraseñas fuerte
    'vim /etc/login.defs' ->   en la seccion PASS_MAX_DAYS... Tiempo contrasena
    Luego se instalo la lib libpam-pwquality
    'vim etc/pam.d/common-password' -> Digitos y elementos de la contrasena
    Recordar u:upper, d:digit, l:lower, difok:Al menos X caracteres que no sean parte de la anterior contrasena
    Validar que usuario cumpla con los dias
    'sudo chage -l nombre_usuario'
    Si no cumple
    'sudo chage -m/-M # nombre_usuario'
    -m minimo de dias entre cambio de contrasena
    -M Maximo de dias para cambio de contrasena
  
  Crear un nuevo grupo
  'sudo addgroup nombre_grupo'

  Si desea ver los grupos existentes y los usuarios en los grupos
  'cat /etc/group'

  Adicionar a usuario en un grupo
  'sudo adduser nombre_usuario nombre_grupo'
  Si desea validar que el usuario fua agregado al grupo
  'getent group nombre_grupo'
  
  Si se desea eliminar a un usuario de un grupo
  'sudo deluser nombre_usuario nombre_grupo'

Servidor y particiones:
	