<?php

  function generateQuery()
  {
    $queryArray[] = attributeExists("isbn");
    $queryArray[] = attributeEquals("izdanje");
    $queryArray[] = attributeEquals("uvez");
    $queryArray[] = elementExists("naslov");
    $queryArray[] = elementExists("podnaslov");
    $queryArray[] = elementExists("kategorija");
    $queryArray[] = longContains('autor', 'ime', 'ime_autora');
    $queryArray[] = longContains('autor', 'prezime', 'prezime_autora');
    if (!empty($_REQUEST['izdavac']))
    {
      $queryArray[] = longContains('izdavac', 'naziv', 'naziv_izdavaca');
    }
    /*if (!empty($_REQUEST['datum_izdanja']))
    {
      $datum = explode(".", $_REQUEST['datum_izdanja']);
      if ($datum)
    }*/
    $queryArray[] = attributeExists("broj_stranica");
    $queryArray[] = attributesExist('jezik');
    $queryArray[] = elementsExist('ocjena');
    $queryArray = array_remove_empty($queryArray);
    $query = implode(" and ", $queryArray);

    if (empty($query))
      return "/knjiznica/knjiga";

    $query = "/knjiznica/knjiga[" . $query . "]";
    return $query;
  }

  function attributesExist($attributeName)
  {
    if (!empty($_REQUEST[$attributeName]))
    {
      foreach ($_REQUEST[$attributeName] as $attribute)
      {
        $queryFragment[] = "@" . $attributeName . "='" . $attribute . "'";
      }
      return "(" . implode(" or ", $queryFragment) . ")";
    }
    else
      return "";
  }

  function elementsExist($elementName)
  {
    if (!empty($_REQUEST[$elementName]))
    {
      foreach ($_REQUEST[$elementName] as $element)
      {
        $queryFragment[] = $elementName . "='" . $element . "'";
      }
      return "(" . implode(" or ", $queryFragment) . ")";
    }
    else
      return "";
  }

  function attributeExists($attributeName)
  {
    if(!empty($_REQUEST[$attributeName]))
      return "contains(@" . $attributeName . ",'" . $_REQUEST[$attributeName] . "')";
    return "";
  }

function attributeEquals($attributeName)
  {
    if(!empty($_REQUEST[$attributeName]))
      return "@" . $attributeName . "='" . $_REQUEST[$attributeName] . "'";
    return "";
  }

  function elementExists($elementName)
  {
    if(!empty($_REQUEST[$elementName]))
      return "contains(" . $elementName . ",'" . $_REQUEST[$elementName] . "')";
    return "";
  }

  function getElementValue($node, $elementName)
  {
    return $node->getElementsByTagName($elementName)->item(0);
  }

  function longContains($parentElementName, $childElementName, $formElementName)
  {
    if (!empty($_REQUEST[$formElementName]))
    {
      return $parentElementName . "[contains(" . $childElementName . ", '" . $_REQUEST[$formElementName] . "')]";
    }
  }

  function array_remove_empty($arr)
  {
    $narr = array();
    while(list($key, $val) = each($arr))
    {
      if (is_array($val))
      {
        $val = array_remove_empty($val);
        // does the result array contain anything?
        if (count($val)!=0)
        {
          // yes :-)
          $narr[$key] = $val;
        }
      }
      else
      {
        if (trim($val) != "")
        {
          $narr[$key] = $val;
        }
      }
    }
    unset($arr);
    return $narr;
  }

?>