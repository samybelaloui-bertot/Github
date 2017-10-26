<?php
      function smarty_function_filtre_categorie($params, &$smarty)
      {
       //include 'gestionbdd.php';
        try{
          //Connexion à notre base de données
            $objet = new Gestionbdd;
            $connexion=$objet->connexion();

            //Définition de la requête à exécuter
           $sql_query ="SELECT meridien.nom  as 'Categorie' FROM meridien
                        GROUP BY meridien.nom";

            //Préparationet exécution de la requête 
            $sth = $connexion->prepare($sql_query);
            $sth->execute();

            //On récupère toutes les lignes retournées par notre requête dans un objet
            $liste_categorie=array();
            $i=0;
            // On vient remplir le tableau avec les 2 élèments qui nous interesse
              while ($donnees = $sth->fetch())
              {
               $liste_categorie[$i]['Categorie'] = $donnees['Categorie'];    
               $i++;
            }
            //On transmet le tableau au template
            $smarty-> assign('liste_categorie',$liste_categorie);
          
          }
          catch(PDOException $e) {
          echo'{"error":{"text":'. $e->getMessage() .'}}';
         }
      }
?>  