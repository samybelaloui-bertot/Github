<?php
          include 'gestionbdd.php';

          //Connexion à notre base de données

            $objet = new Gestionbdd;
            $connexion=$objet->connexion();

            $term = $_GET['term'];

            //Définition de la requête à exécuter
            $sql_query ="SELECT keywords.name  as 'Keywords' FROM keywords
                         WHERE keywords.name LIKE :term
                         GROUP BY keywords.name
                         LIMIT 5";

            //Préparation et exécution de la requête 
            $requete = $connexion->prepare($sql_query);

            $requete->execute(array('term' => $term.'%'));

            //$sth->execute();
            //On récupère toutes les lignes retournées par notre requête dans un objet
            $array = array(); // on créé le tableau

            while($donnee = $requete->fetch()) // on effectue une boucle pour obtenir les données
            {
                array_push($array, $donnee['Keywords']); // Ajout à notre tableau
            }

            echo json_encode($array); // Conversion en JSON                
?>  