export my_hostname="cluster1"
export my_ip_suffix="31"

echo "+--------------------------------+"
echo "| FeTS - Fehlertolerante Systeme |" 
echo "+--------------------------------+"
echo "Praktikum: Versuch 3, CLUSTER"
echo "Version:   v2023-10-13"
echo "Host:      ClusterVM-1"
echo "IP:        192.168.205.31"

if [ "$(id -u)" -ne 0 ];
  then echo "Skript muss als root ausgefuehrt werden."
  exit 1
fi

if [ -z "${my_hostname}" ] ; then echo "Variable my_hostname nicht gesetzt!" ; fi
if [ -z "${my_ip_suffix}" ] ; then echo "Variable my_ip_suffix nicht gesetzt!" ; fi

echo "-------------------------"
echo "- Anpassung lokaler IP Adresse"
#sudo /bin/sed -i "s/10.0.0.51/10.0.0.${my_ip_suffix}/g" /etc/network/interfaces
sudo /bin/sed -i "s/192.168.205.51/192.168.205.${my_ip_suffix}/g" /etc/network/interfaces

echo "-------------------------"
echo "- Anpassung lokaler Hosts Tabelle"
sudo tee /etc/hosts <<EOF
127.0.0.1 localhost
# Altes Praktikumsnetz
#10.0.0.31 cluster1.itsdomain.local cluster1
#10.0.0.32 cluster2.itsdomain.local cluster2
#10.0.0.33 cluster3.itsdomain.local cluster3
192.168.205.31 cluster1.itsdomain.local cluster1
192.168.205.32 cluster2.itsdomain.local cluster2
192.168.205.33 cluster3.itsdomain.local cluster3
EOF

echo "-------------------------"
echo "- Anpassung Hostname"
sudo tee /etc/hostname <<EOF
${my_hostname}
EOF

echo "-------------------------"
echo "Anpassungen abgeschlossen"
echo ""
echo "!!!---!!!---!!!---!!!---!!!---"
echo "Bitte starten Sie die VM neu"
echo "!!!---!!!---!!!---!!!---!!!---"