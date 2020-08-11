<html>
    <head>
        <meta charset="UTF-8">
        <title>
            Bảng
        </title>
    </head>
    <body>
        <?php
            echo "tạo bảng";
            echo "<table width=600 border=2>";
            for ($i=1 ; $i<=3; $i++){
                echo "<tr>";
                for ($j=1 ; $j<=3; $j++){
                    echo "<td>&nbsp;</td>";
                }
                echo "<br/>";
                echo "</tr>";
            }
            echo "</table>"
        ?>
    </body>
</html>