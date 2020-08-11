<html>
    <head>
        <meta charset="UTF-8">
        <title>
            Bảng
        </title>
    </head>
    <body>    
    <form action=# method="POST" name="formDraw">
            <table class="form">
                <tr>
                    <th> Số hàng</th>
                    <td>
                        <input type="number" name="row" class="from-control" required>

                    </td>
                </tr>
                <tr>
                    <th> Số cột</th>
                    <td>
                        <input type="number" name="col" class="from-control" required>
                    </td>
                </tr>
                <tr>
                    <td>
                        <button class="control-form" type="reset">Xoá</button>
                    </td>
                    <td>
                        <button class="control-form" type="submit">Vẽ</button>
                    </td>
                </tr>
            </table>
        </form>
        
        
        
        
        <?php
        if (isset($_POST["row"]) && isset($_POST["col"]))
        {
            echo "tạo bảng";
            echo "<table width=600 border=2>";
            for ($i=1 ; $i<=$_POST["row"]; $i++){
                echo "<tr>";
                for ($j=1 ; $j<=$_POST["col"]; $j++){
                    echo "<td>";
                    if ($j<=$i) {
                        echo $j;
                    } else {
                        echo "&nbsp;";
                    }
                    echo "</td>";
                }
                echo "<br/>";
                echo "</tr>";
            }
            echo "</table>";
        }
        ?>
    </body>
</html>