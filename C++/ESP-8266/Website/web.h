const char MAIN_PAGE[] PROGMEM = R"rawliteral(
<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
</head>

<body>
    <h2>LAMPU</h2>
    <h3>Lampu 1</h3>
    <input type="checkbox" onchange="controlLed(1, this.checked)" id="led1">
    <h3>Lampu 2</h3>
    <input type="checkbox" onchange="controlLed(2, this.checked)" id="led2">
    <h3>Lampu 3</h3>
    <input type="checkbox" onchange="controlLed(3, this.checked)" id="led3">

    <script>
        window.onload = function () {
            for (let x = 1; x <= 3; x++) {
                document.getElementById('led' + x).checked =
                    localStorage.getItem('led' + x) === 'true';
            }
        };

        function controlLed(nomor, status) {
            localStorage.setItem('led' + nomor, status);
            location.href = '/led' + nomor + '/' + (status ? '1' : '0');
        }
    </script>
</body>

</html>

)rawliteral";