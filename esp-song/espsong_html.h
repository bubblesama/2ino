String rootPageHtml = "<!DOCTYPE HTML><html><body><h2>esp song</h2><a href='/chirp'>chirp</a></body></html>\r\n";
String chirpPageHtml = "<?xml version='1.0'?><html><head><title>esp-song command panel</title><style>.chirp-button{background-color:#42f5bfc9;color:black;padding:4em;font-size:3em}</style></head><body><h1>esp-song command panel</h1><button id='chirp-main' class='chirp-button' onclick='chirp();'>chirp</button><button id='chirp-random' class='chirp-button' onclick='random();'>random</button><script>;const SERVER_IP='192.168.1.35';function chirp(){console.log('chirp IN');var n=new XMLHttpRequest();n.open('GET','http://'+SERVER_IP+'/chirp');n.send(null)};function random(){console.log('random IN');var n=new XMLHttpRequest();n.open('GET','http://'+SERVER_IP+'/random');n.send(null)};</script></body></html>";
