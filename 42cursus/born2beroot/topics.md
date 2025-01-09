
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


