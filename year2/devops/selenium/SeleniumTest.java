// Generated by Selenium IDE
import org.junit.Test;
import org.junit.Before;
import org.junit.After;
import static org.junit.Assert.*;
import static org.hamcrest.CoreMatchers.is;
import static org.hamcrest.core.IsNot.not;
import org.openqa.selenium.By;
import org.openqa.selenium.WebDriver;
import org.openqa.selenium.firefox.FirefoxDriver;
import org.openqa.selenium.chrome.ChromeDriver;
import org.openqa.selenium.remote.RemoteWebDriver;
import org.openqa.selenium.remote.DesiredCapabilities;
import org.openqa.selenium.Dimension;
import org.openqa.selenium.WebElement;
import org.openqa.selenium.interactions.Actions;
import org.openqa.selenium.support.ui.ExpectedConditions;
import org.openqa.selenium.support.ui.WebDriverWait;
import org.openqa.selenium.JavascriptExecutor;
import org.openqa.selenium.Alert;
import org.openqa.selenium.Keys;
import java.util.*;
import java.net.MalformedURLException;
import java.net.URL;
public class SeleniumtestTest {
  private WebDriver driver;
  private Map<String, Object> vars;
  JavascriptExecutor js;
  @Before
  public void setUp() {
    driver = new FirefoxDriver();
    js = (JavascriptExecutor) driver;
    vars = new HashMap<String, Object>();
  }
  @After
  public void tearDown() {
    driver.quit();
  }
  @Test
  public void seleniumtest() {
    driver.get("https://www.campus.fh-aachen.de/campus/all/groups.asp?tguid=0x6D4B18790AAA451FAAEC4E1140F42595&lang=de");
    driver.manage().window().setSize(new Dimension(859, 913));
    driver.findElement(By.linkText("Suchen")).click();
    driver.findElement(By.id("find")).click();
    driver.findElement(By.id("find")).sendKeys("Kryptologie");
    driver.findElement(By.id("searchobject")).click();
    {
      WebElement dropdown = driver.findElement(By.id("searchobject"));
      dropdown.findElement(By.xpath("//option[. = 'Modul']")).click();
    }
    driver.findElement(By.cssSelector("#searchobject > option:nth-child(2)")).click();
    driver.findElement(By.id("campusSearchButton")).click();
    driver.findElement(By.linkText("Suchen")).click();
    driver.findElement(By.id("find")).click();
    driver.findElement(By.id("find")).sendKeys("Hoever, Georg");
    driver.findElement(By.id("searchobject")).click();
    {
      WebElement dropdown = driver.findElement(By.id("searchobject"));
      dropdown.findElement(By.xpath("//option[. = 'Person (Nachname und Vorname)']")).click();
    }
    driver.findElement(By.cssSelector("#searchobject > option:nth-child(3)")).click();
    driver.findElement(By.id("campusSearchButton")).click();
    driver.findElement(By.linkText("Suchen")).click();
    try {
      Thread.sleep(15000);
    } catch (InterruptedException e) {
      e.printStackTrace();
    }
  }
}
